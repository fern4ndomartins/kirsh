#include "utils.h"

std::string execCommand(const char* cmd) {
    std::array<char, 128> buffer{};
    std::string result;
    
    auto pipe_deleter = [](FILE* file) { 
    if (file) pclose(file); 
    };

    std::unique_ptr<FILE, decltype(pipe_deleter)> pipe(popen(cmd, "r"), pipe_deleter);

    if (!pipe) throw std::runtime_error("popen() failed!");
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}