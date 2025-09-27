#pragma once
#include <iostream>
#include <string>
#include <filesystem>

struct Model {
    std::string architecture;
    std::string activation_function; // supposed to be an enum with #defines 
    int params;
    double learning_rate;
    //;;;;;;;;;;;;;
};

struct Dataset {
    std::uintmax_t size;
};

std::uintmax_t get_dataset_size(std::string);