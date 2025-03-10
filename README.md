# Operating System Sessional

This repository contains implementations of various Operating System concepts and scheduling algorithms using the C programming language on a Linux platform. The experiments include CPU scheduling algorithms, process synchronization problems, and resource allocation techniques.

## List of Experiments

### CPU Scheduling Algorithms
1. **First-Come, First-Served (FCFS) Scheduling**
2. **Shortest-Job-First (SJF) Scheduling**
3. **Priority Scheduling**
4. **Round Robin (RR) Scheduling**

### Process Synchronization Problems
5. **Producer-Consumer Problem** - Implements inter-process communication using shared memory and synchronization mechanisms.
6. **Bounded-Buffer Problem** - Solves the problem of limited buffer space in producer-consumer communication.
7. **Readers-Writers Problem** - Implements a synchronization solution where multiple readers can read simultaneously, but a writer must have exclusive access.
8. **Dining Philosophers Problem** - Demonstrates deadlock and starvation scenarios in concurrent programming.
9. **Sleeping Barber Problem** - Models synchronization in a system with multiple waiting processes.

### Resource Allocation & Deadlock Handling
10. **Resource-Allocation Graph Algorithm** - Implements resource allocation and deadlock detection using a graph-based approach.
11. **Banker’s Algorithm** - Implements a deadlock avoidance algorithm using a safe sequence of resource allocation.

## Prerequisites
- Linux Operating System
- GCC Compiler
- Basic knowledge of C programming and Operating System concepts

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/os-experiments.git
   cd os-experiments
   ```
2. Compile the programs:
   ```bash
   gcc filename.c -o outputfile -pthread
   ```
3. Run the executable:
   ```bash
   ./outputfile
   ```

## Contributing
Feel free to contribute by adding improvements or fixing bugs. Fork the repository, make your changes, and submit a pull request.

## License
This project is open-source and available under the MIT License.
