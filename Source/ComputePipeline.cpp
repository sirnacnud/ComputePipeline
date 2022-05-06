#include "ComputePipeline.hpp"

#include <functional>

#include "ActionObject.hpp"
#include "PipelineTask.hpp"

ComputePipeline::ComputePipeline()
    : mThread(nullptr)
{
}

ComputePipeline::~ComputePipeline() {
    if (mThread) {
        mThread->detach();
        delete mThread;
    }
}

std::future<std::shared_ptr<ActionObject>> ComputePipeline::addTask(const std::string& url) {
    std::shared_ptr<PipelineTask> pipelineTask(new PipelineTask(url, mActionFactory));
    
    std::packaged_task<std::shared_ptr<ActionObject> ()> packagedTask(std::bind(&PipelineTask::run, pipelineTask));
    std::future<std::shared_ptr<ActionObject>> future = packagedTask.get_future();

    std::unique_lock<std::mutex> lock(mTaskMutex);
    mTaskQueue.push_back(std::move(packagedTask));
    lock.unlock();

    mTaskCondition.notify_one();

    return future;
}

void ComputePipeline::start() {
    if (mThread) {
        return;
    }

    mThread = new std::thread(&ComputePipeline::processTasks, this);
}

void ComputePipeline::stop() {
    mThread->detach();

    delete mThread;
    mThread = nullptr;
}

void ComputePipeline::processTasks() {
    std::unique_lock<std::mutex> lock(mTaskMutex, std::defer_lock);

    while (true) {
        lock.lock();

        if (mTaskQueue.empty()) {
            mTaskCondition.wait(lock);
        }

        std::packaged_task<std::shared_ptr<ActionObject> ()> task = std::move(mTaskQueue.front());
        mTaskQueue.pop_front();

        lock.unlock();

        task();
    }
}
