# CPU Scheduling Simulator

This project is a C-based simulation of CPU scheduling algorithms. It implements three scheduling algorithms:

1. **First-Come, First-Served (FCFS)**
2. **Shortest Job First (SJF)**
3. **Round Robin (RR)**

The program allows users to input details of processes, including arrival times and burst times, and calculates the waiting time, turnaround time, and completion time for each process. It also computes the average waiting and turnaround times and optionally displays a Gantt chart.

---

## Features

- **User Input**: Number of processes, arrival times, burst times, and time quantum for Round Robin.
- **Scheduling Algorithms**: Simulates FCFS, SJF, and Round Robin.
- **Performance Metrics**: Calculates waiting time, turnaround time, and average values for all processes.
- **Process Visualization**: Displays process details in a tabular format.

---

## Requirements

- GCC Compiler (or any C compiler)
- Basic knowledge of CPU scheduling algorithms

---

## Compilation and Execution

### 1. Clone the Repository
```bash
$ git clone https://github.com/stephenombuya/CPU-Scheduling-Simulator
$ cd cpu-scheduling-simulator
```

### 2. Compile the Program
```bash
$ gcc cpu_scheduling.c -o cpu_scheduling
```

### 3. Run the Program
```bash
$ ./cpu_scheduling
```

---

## User Input

The program prompts for the following inputs:

1. **Number of Processes**: Total number of processes to schedule.
2. **Process Details**: Arrival time and burst time for each process.
3. **Scheduling Algorithm**: Choice of FCFS, SJF, or Round Robin.
4. **Time Quantum**: Required only for Round Robin.

---

## Output

The program displays the following:

- Process ID, Arrival Time, Burst Time, Waiting Time, Turnaround Time, and Completion Time.
- Average Waiting Time and Turnaround Time.

Example Output:
```
Choose the scheduling algorithm:
1. FCFS
2. SJF
3. Round Robin
Choice: 1

Process	Arrival	Burst	Waiting	Turnaround	Completion
P1		0		5		0		5			5
P2		2		3		3		6			8
P3		4		8		4		12			16

Average Waiting Time: 2.33
Average Turnaround Time: 7.67
```

---

## Supported Scheduling Algorithms

### 1. **First-Come, First-Served (FCFS)**
- Processes are scheduled in the order of their arrival times.
- Non-preemptive algorithm.

### 2. **Shortest Job First (SJF)**
- Processes with the shortest burst times are scheduled first.
- Non-preemptive algorithm.

### 3. **Round Robin (RR)**
- Processes are executed in a cyclic order with a fixed time quantum.
- Preemptive algorithm.

---

## Code Structure

- **Process Struct**: Represents a process with attributes like `id`, `arrival_time`, `burst_time`, `remaining_time`, etc.
- **Main Function**: Handles user input and algorithm selection.
- **Helper Functions**:
  - `fcfs()`: Implements First-Come, First-Served scheduling.
  - `sjf()`: Implements Shortest Job First scheduling.
  - `round_robin()`: Implements Round Robin scheduling.
  - `calculate_average_times()`: Calculates average waiting and turnaround times.

---

## Customization

You can extend the project to:

- Add support for additional algorithms like Priority Scheduling or Multilevel Queue.
- Include a Gantt chart for visualization.
- Improve the user interface.

---

## Contribution

Feel free to fork the repository, create a new branch, and submit a pull request for improvements or bug fixes.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---
