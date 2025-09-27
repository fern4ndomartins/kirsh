// first model to handle: MLP. apparently you can just split the dataset and thats enough so its literally the 
// perfect case 
// obviously the split still depends on the compute resources of each worker so its a perfect fit for an mvp 
// question now is how to handle commits, versions, configs and etc

// first, reads dataset, split according to compute on each worker, then estimates the time to train
// send data set chunk, send code, send command to run code, updates user for progress, gets an answer when finishes
// in this case what we want are the weights.

#include "mlp.h"

std::uintmax_t get_dataset_size(const std::string& dataset) {
    try {
        if (!std::filesystem::exists(dataset)) {
            throw std::runtime_error("File does not exist");
        }
        return std::filesystem::file_size(dataset);
    } catch (const std::filesystem::filesystem_error& ex) {
        throw std::runtime_error(std::string("Filesystem error: ") + ex.what());
    }

}