#include <iostream>

#include "ComputePipeline.hpp"
#include "ContainerObject.hpp"
#include "JsonObject.hpp"

int main() {
    ComputePipeline pipeline;

    // Queue processing a bundle
    std::future<std::shared_ptr<ActionObject>> bundleFuture = pipeline.addTask("bundle://test.app");
    
    // Queue processing a json file
    std::future<std::shared_ptr<ActionObject>> jsonFuture = pipeline.addTask("file://test.json");

    pipeline.start();
    
    try {
        std::shared_ptr<ActionObject> bundleActionObject = bundleFuture.get();
        std::shared_ptr<ActionObject> jsonActionObject = jsonFuture.get();
        
        if (std::shared_ptr<ContainerObject> containerObject = std::dynamic_pointer_cast<ContainerObject>(bundleActionObject); containerObject) {
            // Do something with final output
            std::cout << "Received ContainerOject" << std::endl;
        }
        
        if (std::shared_ptr<JsonObject> jsonObject = std::dynamic_pointer_cast<JsonObject>(jsonActionObject); jsonObject) {
            // Do something with final output
            std::cout << "Received JsonObject" << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    pipeline.stop();
}
