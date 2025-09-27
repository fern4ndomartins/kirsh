#include <iostream>
#include "src/worker/worker.h"
#include "src/master/master.h"

int main(int argc, char* argv[]) {
    std::string kind = argv[1];
    if (kind == "master") {
        Master *master = new Master();
    }

    if (kind == "worker") {
        // read specs and connect to server 
        std::string serverip = "127.0.0.1";
        Worker *worker = new Worker(serverip, "8080");
    }
}