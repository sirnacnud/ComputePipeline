# Compute Pipeline
This project is a homework assignment for a job interview.

## Compiling
Use cmake to compile the project.

## Usage
The `ComputePipeline` object handles processing the URLs you supply to it. You will get a `std::future<ActionObject>` back which can be used to retrive the final `ActionObject` for your URL. 

The `ComputePipeline` has it's own thread and you can submit multiple URLs. These will be processed serially. If you would like to run multiple URLs in parallel, you should use more than one instance of `ComputePipeline`.

## Supported URLs
- **file://** - The file at this URL will be loaded then further processed depending on what file it is.
- **http(s)://**  - A HTTP request would be made to fetch this resource and then further processed depending on what type of data it is, ie JSON or file data.
- **bundle://** - A bundle similar to bundles in macOS. All the files of the bundle will be loaded into a flat list and then each item is processed depending on what file it is. The final output is a `ContainerObject`.

## Action Transformations
- **Image** - Images are decoded into a `ImageObject` with a buffer of pixel data, along with information about width, height, and bytes per pixel.
-  **Compressed** - Compressed items such as a bzip file will be decompressed, then the decompressed data is further processed depending on what it is.
- **JSON** - JSON objects will be decoded into a `JsonObject` which you can query values from.

## Example Usage
```
ComputePipeline pipeline;

// Queue processing a json file
std::future<std::shared_ptr<ActionObject>> jsonFuture = pipeline.addTask("file://test.json");

pipeline.start();
    
try {
    std::shared_ptr<ActionObject> jsonActionObject = jsonFuture.get();
} catch (std::exception& e) {
    std::cout << e.what() << std::endl;
}

pipeline.stop();
```

`main.cpp` contains a similar example.

## Further Development
These are things I would of liked to develop further, but I didn't have enough time.

- Add parallel processing of bundle items. Currently they are processed serially.
- Keep bundle hierarchy of containers for items rather than putting them in a flat list.
- Action instances are created and destroyed per single use. There could be better memory use if we reused them or refactored the solution to not be based on creating instances for each action.
