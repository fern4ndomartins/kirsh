# Kirsh - Distributed ML Orchestrator (2025)

**Creator & Maintainer:** [fern4ndomartins](https://github.com/fern4ndomartins)  
**License:** Open Source  

Kirsh is a **modern C++ framework** for **distributed machine learning training orchestration**.  
The project was born from the idea of providing a **lightweight, efficient, and extensible** alternative for researchers, hobbyists, and developers who want to **extract maximum performance from small or mid-sized clusters**, without relying on complex enterprise-level solutions.  

Kirsh implements a **custom protocol** over **TCP sockets**, enabling high-performance communication between nodes, dynamic load balancing, and seamless integration with **popular ML frameworks via Python bindings**.  

---

## ✨ Features

- ⚡ **Modern C++ Core**  
  API designed with *templates*, *RAII*, and *move semantics* for maximum performance and memory safety.  

- 🌐 **Custom Distributed Protocol**  
  Synchronization of gradients, checkpoints, and control messages over TCP, designed to minimize latency and overhead.  

- 📊 **Smart Dataset Partitioning**  
  Internal algorithms to balance dataset distribution dynamically, maximizing the use of each machine’s resources.  

- 🐍 **Python Bindings**  
  Direct usage of Kirsh inside projects that leverage PyTorch, TensorFlow, or other ML frameworks.  

- 🔧 **Local-First Scalability**  
  Targeted at academic clusters, research labs, and home setups with multiple machines.  

---

## 🚀 Getting Started

### Requirements

- C++20 or higher (compatible compiler: g++, clang++)
- CMake ≥ 3.20
- Python ≥ 3.10 (for bindings)
- Linux

### Build

```bash
git clone https://github.com/fern4ndomartins/kirsh.git
cd kirsh
mkdir build && cd build
cmake ..
make -j$(nproc)
