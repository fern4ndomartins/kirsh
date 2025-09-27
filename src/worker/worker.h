#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <array>
#include "../../common/utils.h"
#include "../network/network.h"

struct OSInfo {
    std::string os;
    std::string distro;
    std::string version;
};

struct CPUInfo {
    std::string vendor;
    std::string model;
    int sockets;
    int cores;
    int threads;
    double baseFrequencyGHz;
};

struct MemoryInfo {
    std::size_t totalBytes;
    std::size_t availableBytes;
};

struct GPUInfo {
    bool any_gpus_available;
    std::string vendor;
    std::string model;
    std::size_t memoryBytes;
    std::string driverVersion;
};

class Worker {
public:
    OSInfo osinfo;
    CPUInfo cpuinfo;
    MemoryInfo memoryinfo;
    GPUInfo gpuinfo;
    Worker(std::string, std::string);
    std::string getCpuInfo();
    std::string getMemInfo();
    std::string getGpuInfo();
};