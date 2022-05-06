cmake_minimum_required(VERSION 3.0)

project(ComputePipeline)

set(CMAKE_CXX_STANDARD 17)

set(headers ${headers}
    Source/Action.hpp
    Source/ActionFactory.hpp
    Source/ActionObject.hpp
    Source/BundleLoadAction.hpp
    Source/ComputePipeline.hpp
    Source/ContainerObject.hpp
    Source/DataObject.hpp
    Source/DecodeImageAction.hpp
    Source/DecodeJsonAction.hpp
    Source/DecompressAction.hpp
    Source/FileLoadAction.hpp
    Source/HTTPLoadAction.hpp
    Source/ImageObject.hpp
    Source/JsonObject.hpp
    Source/MimeType.hpp
    Source/PipelineTask.hpp
)

set(sources ${sources} 
    Source/ActionFactory.cpp
    Source/ActionObject.cpp
    Source/BundleLoadAction.cpp
    Source/ComputePipeline.cpp
    Source/ContainerObject.cpp
    Source/DataObject.cpp
    Source/DecodeImageAction.cpp
    Source/DecodeJsonAction.cpp
    Source/DecompressAction.cpp
    Source/FileLoadAction.cpp
    Source/HTTPLoadAction.cpp
    Source/ImageObject.cpp
    Source/JsonObject.cpp
    Source/PipelineTask.cpp
    Source/main.cpp
)

add_executable(CompilePipelineExample ${sources} ${headers})
