#ifndef COMPUTE_PIPELINE_HPP
#define COMPUTE_PIPELINE_HPP

#include <future>
#include <mutex>
#include <queue>

#include "ActionFactory.hpp"

class ActionObject;

/// Main object for using the Pipeline
/// @note This Pipeline will use it's own thread to do the processing
class ComputePipeline {
public:
    ComputePipeline();
    
    ~ComputePipeline();

    /// Submit URLs to process in the pipeline
    /// @param url: URL to process (can be file, http(s), or a bundle URI)
    /// @return Future which will receive the final ActionObject
    std::future<std::shared_ptr<ActionObject>> addTask(const std::string& url);
    
    /// Starts the pipeline processing
    void start();
    
    /// Stops the pipeline processing
    void stop();
    
private:
    void processTasks();
    
private:
    ActionFactory mActionFactory;
    std::thread* mThread;
    std::mutex mTaskMutex;
    std::deque<std::packaged_task<std::shared_ptr<ActionObject> ()>> mTaskQueue;
    std::condition_variable mTaskCondition;
};

#endif
