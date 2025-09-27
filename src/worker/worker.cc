#include "worker.h"

Worker::Worker(std::string ip, std::string port) {
    asio::io_context io;
    ClientSession *session = new ClientSession(io, ip, port);
}

std::string Worker::getCpuInfo() {
    return execCommand("lscpu");
} 

std::string Worker::getMemInfo() {
    return execCommand("free -b");
} 

std::string Worker::getGpuInfo() {
    return execCommand("lspci | grep VGA");
} 