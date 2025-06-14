# CPU Scheduler: Algorithm Simulator & Performance Evaluator

## 📋 Project Overview

This project is a C++-based simulator that implements and evaluates four classic CPU scheduling algorithms:

* **First Come First Serve (FCFS)**
* **Shortest Job First (SJF)**
* **Round Robin (RR)**
* **Priority Scheduling (PS)**

The application allows users to enter process details (burst time, priority, and time quantum), view execution order through a Gantt chart, and compare the performance of each algorithm by calculating average waiting times.

---

## 🎯 Features

* ✅ Menu-driven user interface
* ✅ Supports 4 scheduling algorithms
* ✅ Visual Gantt chart generation
* ✅ Average waiting time calculation
* ✅ Algorithm performance comparison
* ✅ Robust error handling and input validation

---

## 🔧 Technologies Used

* **Language:** C++
* **Environment:** Console-based application
* **Compiler:** Any C++11-compatible compiler

---

## 📝 Data Structures

### `struct Process`

Represents a process with the following fields:

* `burst_time`: Required CPU time
* `waiting_time`: Time spent in the ready queue
* `backupburst_time`: Original burst time (for sorted display)
* `priority`: Integer priority (lower means higher priority)
* `process_id`: Unique identifier (e.g., `P1`, `P2`)

---

## 🛠️ Main Functionalities

### 🔹 takeInput()

Prompts the user to enter burst times (and priority where applicable) for all processes. Ensures inputs are positive and valid.

### 🔹 Average\_Waiting\_Time()

Calculates the average waiting time across all processes by summing individual waiting times and dividing by the number of processes.

### 🔹 displayGanttChart()

Displays a formatted Gantt chart showing process execution order along with completion times.

### 🔹 FCFS(), SJF(), RoundRobin(), PriorityScheduling()

Each of these functions implements one of the four scheduling algorithms:

* `FCFS()`: Executes processes in the order they arrive.
* `SJF()`: Sorts and runs processes in order of burst time.
* `RoundRobin()`: Executes using a fixed time quantum in cyclic order.
* `PriorityScheduling()`: Runs processes based on ascending priority values.

All of them:

* Calculate individual waiting times
* Output results in a table
* Display Gantt chart
* Return average waiting time

### 🔹 EvaluateAlgorithms()

Takes a common input set, runs all four scheduling algorithms, compares their average waiting times, and determines the best-performing one.

---

## ⚙️ How to Run

1. Compile with any standard C++ compiler:

   ```bash
   g++ CPU_Scheduler_Algorithm_Project.cpp -o scheduler
   ./scheduler
   ```
   - If you are running it on VS Code, just use the 'Run Code'▶️ option.
2. **Using the Application**

   Once the program starts, you'll see a menu with the following options:

   ```
   1. Scheduling Algorithm
   2. Algorithm Evaluator
   3. Exit the program
   ```

   * Choose **1** to run a specific scheduling algorithm (FCFS, SJF, RR, PS).

   * Choose **2** to evaluate and compare **all algorithms** on the same input.

     You will be asked to enter:

     * The number of processes
     * Their burst times
     * Priorities (if required)
     * Quantum (for Round Robin)

     After input, the program will display:

     * Process Table
     * Gantt Chart
     * Average Waiting Time
     * The best-performing algorithm (based on evaluation)

---

## 💻 User Interface

### Main Menu

![Image](https://github.com/user-attachments/assets/a9131c9a-d631-4a18-a3b8-f5b598cb906a)

### Scheduling Algorithms

![Image](https://github.com/user-attachments/assets/49bdeb5e-3f97-4c4a-a8f2-8762f66955d7)

Each option lets you:

* Enter number of processes
* Provide burst time (+ priority/quantum where applicable)
* See Gantt chart and waiting times

---

## 📤 Sample Output

### First Come, First Serve (FCFS):

![Image](https://github.com/user-attachments/assets/0728f39d-92fc-495e-84ac-1156b702610c)

### Shortest Job First (SJF):

![Image](https://github.com/user-attachments/assets/f42fe41f-ae4c-4919-9125-a1f99401c83d)

### Round Robin (RR):

![Image](https://github.com/user-attachments/assets/d9258e57-768d-44ec-9aca-2ce3ffa4d38f)

### Priority Scheduling (PS):

![Image](https://github.com/user-attachments/assets/8404a0f3-4d39-4b8f-ab1d-c370cb450658)

### Algorithm Evaluator:

![Image](https://github.com/user-attachments/assets/b1da5d59-3655-4cd4-94ff-e408a2f8f94b)

![Image](https://github.com/user-attachments/assets/27b32156-8c1d-4321-9c97-0fa75327b03c)

---

## 📌 Assumptions

* Non-preemptive SJF and Priority Scheduling
* Priority values are positive integers (lower is higher priority)
* No handling of arrival time or termination
* Gantt chart uses fixed-size arrays (scalable within reasonable limits)

---

## 📉 Limitations

* No calculation of turnaround time or response time
* Gantt chart array has a static size limit (affects large datasets)
* Basic sorting used (e.g., bubble sort) which may be inefficient for large inputs

---

## 📚 References

* Operating System Concepts by Abraham Silberschatz
* East West University Operating Systems Course(CSE325) Materials.

---

## 💡 Contributing
Contributions are welcome! Feel free to fork the repository, make your updates, and submit a pull request.

---

## 🛡️ License
This project uses the [**MIT License**](https://opensource.org/licenses/MIT).

---

## 📧 Contact

For any inquiries or feedback, please contact me anytime at <a href="mailto:abdullahasan220618@gmail.com">[abdullahasan220618@gmail.com](mailto:abdullahasan220618@gmail.com)</a>.
