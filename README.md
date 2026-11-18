# University of Delhi — Operating Systems (GE / PME) Practical Lab Programs

This directory contains the verified, complete source code implementations for the DU Operating Systems practical syllabus. Every single file has the complete question and aim clearly written in its header comment.

## 📁 Practical Files Index

| Practical No. | Source File Name | Description & Question Summary | Language / Type |
| :--- | :--- | :--- | :--- |
| **Practical 02** | [`practical02_basic_commands.sh`](file:///home/villen/OS/practical02_basic_commands.sh) | Execution of basic Linux commands (Information Maintenance, File & Directory Management) | Bash Script |
| **Practical 03** | [`practical03_process_pipe_permissions.sh`](file:///home/villen/OS/practical03_process_pipe_permissions.sh) | Process control (`ps`, `kill`), I/O redirection (`>`, `>>`, `<`), pipes (`\|`), protection (`chmod`, `chown`) | Bash Script |
| **Practical 04 (i)** | [`practical04_fork_same_code.cpp`](file:///home/villen/OS/practical04_fork_same_code.cpp) | Process creation using `fork()`: Same program, same code | C++ |
| **Practical 04 (ii)** | [`practical04_fork_diff_code.cpp`](file:///home/villen/OS/practical04_fork_diff_code.cpp) | Process creation using `fork()`: Same program, different code | C++ |
| **Practical 04 (iii)** | [`practical04_fork_wait.cpp`](file:///home/villen/OS/practical04_fork_wait.cpp) | Parent process waiting for child process termination via `wait()` | C++ |
| **Practical 05** | [`practical05_kernel_cpu_info.cpp`](file:///home/villen/OS/practical05_kernel_cpu_info.cpp) | Report Linux kernel version, OS architecture, and CPU hardware details via `uname` and `/proc/cpuinfo` | C++ |
| **Practical 06** | [`practical06_memory_info.cpp`](file:///home/villen/OS/practical06_memory_info.cpp) | Report configured memory, free memory, and buffer cache via `sysinfo` and `/proc/meminfo` | C++ |
| **Practical 07** | [`practical07_file_copy_syscall.cpp`](file:///home/villen/OS/practical07_file_copy_syscall.cpp) | File copy utility using low-level POSIX system calls (`open`, `read`, `write`, `close`) | C++ |
| **Practical 08** | [`practical08_fcfs_scheduling.cpp`](file:///home/villen/OS/practical08_fcfs_scheduling.cpp) | First-Come First-Served (FCFS) CPU scheduling simulation | C++ |
| **Practical 09** | [`practical09_sjf_scheduling.cpp`](file:///home/villen/OS/practical09_sjf_scheduling.cpp) | Shortest Job First (SJF) non-preemptive CPU scheduling simulation | C++ |
| **Practical 10** | [`practical10_priority_scheduling.cpp`](file:///home/villen/OS/practical10_priority_scheduling.cpp) | Priority-based non-preemptive CPU scheduling simulation | C++ |
| **Practical 11** | [`practical11_pthread_sum.cpp`](file:///home/villen/OS/practical11_pthread_sum.cpp) | Multithreaded sum computation of N numbers using POSIX threads (`pthread`) & mutex locks | C++ |
| **Practical 12** | [`practical12_memory_allocation.cpp`](file:///home/villen/OS/practical12_memory_allocation.cpp) | Dynamic memory allocation simulation (First-Fit, Best-Fit, and Worst-Fit) | C++ |

---

## 🛠️ How to Compile & Run

### For C++ Programs:
```bash
# General compilation
g++ -std=c++17 practicalXX.cpp -o practicalXX
./practicalXX

# For Multithreading (Practical 11):
g++ -std=c++17 practical11_pthread_sum.cpp -lpthread -o practical11_pthread_sum
./practical11_pthread_sum
```

### For Shell Scripts:
```bash
chmod +x practical02_basic_commands.sh
./practical02_basic_commands.sh

chmod +x practical03_process_pipe_permissions.sh
./practical03_process_pipe_permissions.sh
```
