#ifndef PIPELINE_TASK_HPP
#define PIPELINE_TASK_HPP

#include <string>

class Action;
class ActionFactory;
class ActionObject;
class ContainerObject;

class PipelineTask {
public:
    PipelineTask(const std::string& url, const ActionFactory& factory);
    
    std::shared_ptr<ActionObject> run();

private:
    std::shared_ptr<ActionObject> processAction(std::shared_ptr<Action> action);
    
    std::shared_ptr<ActionObject> processContainer(std::shared_ptr<ContainerObject> containerObject);
    
private:
    const ActionFactory& mFactory;
    std::string mURL;
};

#endif
