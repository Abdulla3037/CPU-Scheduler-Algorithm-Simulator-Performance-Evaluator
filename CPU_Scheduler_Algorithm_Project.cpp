/*
    Name: Md. Abdulla Hasan
*/
#include <bits/stdc++.h>
using namespace std;

// Structure to represent processes
typedef struct{

    int burst_time; // Process Burst time
    int waiting_time; // Proces Waiting Time
    int backupburst_time; //A backup of the initial burst time (used for displaying)
    int priority; // Priority of the process (lower values indicate higher priority)
    string process_id; // Unique identifier for the process (e.g., "P1", "P2")

}Process ;

/* Function to calculate the average waiting time for all processes
   @Parameters:
    - Process process[]: Array of processes
    - int n: Number of processes
   Functionality: Computes and returns the average waiting time by 
     summing all waiting times and dividing by the number of processes.
   Return Type: double (average waiting time)
 */
double Average_Waiting_Time(Process process[], int n) {

    double total_waiting = 0;
    for (int i = 0; i < n; i++) {
        total_waiting += process[i].waiting_time;
    }
    return total_waiting / n;
}

/* Function to display the Gantt chart for process execution
   @Parameters:
    - string process_ids[]: Array of process IDs
    - int times[]: Array of cumulative times for each process
    - int size: Number of processes in the Gantt chart
   Functionality: Creates a visual representation of the process execution timeline.
   Return Type: void
 */
void displayGanttChart(string process_ids[], int times[], int size) {

    cout << "\n\nGantt Chart:\n";
    for (int i = 0; i < size; i++) {
        cout << "-------";
    }
    cout << "\n|";
    for (int i = 0; i < size; i++) {
        cout << " " << process_ids[i] << "   |";
    }
    cout << "\n";
    for (int i = 0; i < size; i++) {
        cout << "-------";
    }
    cout << "\n0";
    for (int i = 0; i < size; i++) {
        cout << setw(7) << times[i];
    }
    cout << "\n";
}

/* Function to input process details
   @Parameters:
    - Process process[]: Array of processes to be stored
    - int n: Number of processes
    - bool is_priority: Flag indicating whether priority input is required
   Functionality: Captures process details (burst time, and optionally priority) from the user.
   Return Type: void
 */
void takeInput(Process process[], int n, bool is_priority = false) {

    cout << "Enter the Process Burst Time";
    if (is_priority) {
        cout << " and Priority";
    }
    cout << ":\n";
    for (int i = 0; i < n; i++) {

        cout << "P" << i + 1 << " ";
        cin >> process[i].burst_time;

        while (process[i].burst_time <= 0 || cin.fail()) {

            cin.clear();  // clear error flag
            cin.ignore();  // discard invalid input

            cout << "Process Burst Time should be greater than 0.\nEnter the Process Burst Time again\n";
            cout << "P" << i + 1 << " ";
            cin >> process[i].burst_time;
        }

        if (is_priority) {

            cin >> process[i].priority;
            while (process[i].priority <= 0 || cin.fail()) {

                cin.clear();  
                cin.ignore();  

                cout << "Priority should be greater than 0. Enter priority again...\n";
                cin >> process[i].priority;
            }
        }
        process[i].process_id = "P" + to_string(i + 1);
        process[i].backupburst_time = process[i].burst_time;
    }
}

/* Function to implement First Come First Serve (FCFS) scheduling
   @Parameters:
    - int n: Number of processes
    - Process process[]: Array of processes
   Functionality: Executes processes in the order they arrive (First-Come-First-Serve)
   Return Type: double (average waiting time)
 */
double FCFS(int n, Process process[]) {

    cout <<"\n------------------------------\n";
    cout << "First Come First Serve (FCFS)";
    cout <<"\n------------------------------";

    string gantt_pids[n];
    int gantt_waitingtimes[n], gantt_size = 0;

    int waitingtime = 0;
    for (int i = 0; i < n; i++) {

        process[i].waiting_time = waitingtime;
        waitingtime += process[i].burst_time;
        gantt_pids[gantt_size] = process[i].process_id;
        gantt_waitingtimes[gantt_size++] = waitingtime;
    }

    cout << "\nProcess\t\tBurst Time\tWaiting Time";
    for (int i = 0; i < n; i++) {
        cout << "\n" << process[i].process_id << "\t\t" << process[i].burst_time << "\t\t" << process[i].waiting_time;
    }

    double avg_waitingtime = Average_Waiting_Time(process, n);
    cout << "\n\nAverage Waiting Time: " << avg_waitingtime;

    displayGanttChart(gantt_pids, gantt_waitingtimes, gantt_size);

    return avg_waitingtime;
}


/* Function to implement Shortest Job First (SJF) scheduling
   @Parameters:
    - int n: Number of processes
    - Process process[]: Array of processes
   Functionality: Executes processes in ascending order of their burst times.
   Return Type: double (average waiting time)
 */
double SJF(int n, Process process[]) {

    cout <<"\n--------------------------\n";
    cout << "Shortest Job First (SJF)";
    cout <<"\n--------------------------";

    // Sort processes by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (process[j].burst_time > process[j + 1].burst_time) {
                swap(process[j], process[j + 1]);
            }
        }
    }
    int waitingtime = 0;
    string gantt_pids[n];
    int gantt_times[n], gantt_size = 0;

    for (int i = 0; i < n; i++) {

        process[i].waiting_time = waitingtime;
        waitingtime += process[i].burst_time;
        gantt_pids[gantt_size] = process[i].process_id;
        gantt_times[gantt_size++] = waitingtime;
    }

    cout << "\nProcess\t\tBurst Time\tWaiting Time";
    for (int i = 0; i < n; i++) {

        cout << "\n" << process[i].process_id << "\t\t" << process[i].backupburst_time << "\t\t" << process[i].waiting_time;
    }

    double avg_waitingtime = Average_Waiting_Time(process, n);
    cout << "\n\nAverage Waiting Time: " << avg_waitingtime;

    displayGanttChart(gantt_pids, gantt_times, gantt_size);
    return avg_waitingtime;
}

/* Function to implement Round Robin (RR) Scheduling
   @Parameters:
    - int n: Number of processes
    - Process process[]: Array of Process 
    - int quantum: Time quantum for each process execution
   Functionality: Executes processes cyclically, with each process getting a time slice (quantum).
   Return Type: double (average waiting time)
 */
double RoundRobin(int n, Process process[], int quantum) {

    cout <<"\n--------------------------\n";
    cout << "Round Robin (RR)";
    cout <<"\n--------------------------";

    int remaining_burst_time[n];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = process[i].burst_time;
    }
    int turnaround_time = 0;
    string gantt_pids[100];
    int gantt_times[100], gantt_size = 0;

    while (true) {
        bool done = true;

        for (int i = 0; i < n; i++) {

            if (remaining_burst_time[i] > 0) {
                done = false;

                if (remaining_burst_time[i] > quantum) {
                    turnaround_time += quantum;
                    remaining_burst_time[i] -= quantum;
                } 
                else {
                    turnaround_time += remaining_burst_time[i];
                    process[i].waiting_time = turnaround_time - process[i].burst_time;
                    remaining_burst_time[i] = 0;
                }
                gantt_pids[gantt_size] = process[i].process_id;
                gantt_times[gantt_size++] = turnaround_time;
            }
        }
        if (done) {
            break;
        }
    }
    cout << "\nProcess\t\tBurst Time\tWaiting Time";
    for (int i = 0; i < n; i++) {

        cout << "\n" << process[i].process_id << "\t\t" << process[i].burst_time << "\t\t" << process[i].waiting_time;
    }

    double avg_waitingtime = Average_Waiting_Time(process, n);
    cout << "\n\nAverage Waiting Time: " << avg_waitingtime;

    displayGanttChart(gantt_pids, gantt_times, gantt_size);

    return avg_waitingtime;
}

/* Function to implement Priority Scheduling
   @Parameters:
    - int n: Number of processes
    - Process process[]: Array of Process 
   Functionality: Executes processes based on their priority.
   Return Type: double (average waiting time)
 */
double PriorityScheduling(int n, Process process[]) {

    cout <<"\n--------------------------\n";
    cout << "Priority Scheduling (PS)";
    cout <<"\n--------------------------";

    // Sort processes by priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (process[j].priority > process[j + 1].priority) {
                swap(process[j], process[j + 1]);
            }
        }
    }

    string gantt_pids[n];
    int gantt_times[n], gantt_size = 0;

    int waitingtime = 0;
    for (int i = 0; i < n; i++) {

        process[i].waiting_time = waitingtime;
        waitingtime += process[i].burst_time;
        gantt_pids[gantt_size] = process[i].process_id;
        gantt_times[gantt_size++] = waitingtime;
    }

    cout << "\nProcess\t\tBurst Time\tPriority\tWaiting Time";
    for (int i = 0; i < n; i++) {

        cout << "\n" << process[i].process_id << "\t\t" << process[i].burst_time << "\t\t" << process[i].priority << "\t\t" << process[i].waiting_time;
    }

    double avg_waitingtime = Average_Waiting_Time(process, n);
    cout << "\n\nAverage Waiting Time: " << avg_waitingtime;

    displayGanttChart(gantt_pids, gantt_times, gantt_size);
    return avg_waitingtime;
}

/* Function to evaluate and compare scheduling algorithms
   Functionality: Evaluates FCFS, SJF, Round Robin, and Priority Scheduling algorithms. 
   - Takes input for processes, calculates average waiting times for each scheduling algorithm, 
     and identifies the algorithm with the best average waiting time. Displays a comparison 
   Return Type: void
 */
void EvaluateAlgorithms() {

    system("cls");
    cout <<"-------------\n";
    cout << "Evaluator ";
    cout <<"\n-------------\n";

    int n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;

    while (n <= 0 || cin.fail()) {

        cin.clear();  
        cin.ignore();  
        cout << "Process should be greater than 0.\nEnter the processes again: ";
        cin >> n;
    }
    Process process[n];
    Process processCopyFCFS[n], processCopySJF[n], processCopyRR[n], processCopyPS[n];

    // Taking input for processes
    takeInput(process, n, true);
    cout << "Enter time quantum: ";
    cin >> quantum;

    while (quantum <= 0 || cin.fail()) {

        cin.clear();  
        cin.ignore();  

        cout << "Time Quantum should be greater than 0.\nEnter time quantum again: ";
        cin >> quantum;
    }

    // Copying process array for different algorithms to avoid overwriting
    copy(process, process + n, processCopyFCFS);
    copy(process, process + n, processCopySJF);
    copy(process, process + n, processCopyRR);
    copy(process, process + n, processCopyPS);

    // Executing algorithms and calculating average waiting times
    double FCFS_average_waiting_time = FCFS(n, processCopyFCFS);
    double SJF_average_waiting_time = SJF(n, processCopySJF);
    double RR_average_waiting_time = RoundRobin(n, processCopyRR, quantum);
    double PS_average_waiting_time = PriorityScheduling(n, processCopyPS);
    
    double minimum_avgwt = min({FCFS_average_waiting_time, SJF_average_waiting_time, RR_average_waiting_time, PS_average_waiting_time});
    
    cout << "\nComparison";
    cout << "\n------------";
    if (minimum_avgwt == FCFS_average_waiting_time) {
        cout << "\nAfter Comparing all the algorithms, we can evaluate that FCFS has the best average waiting time........" << endl;
    }
    else if (minimum_avgwt == SJF_average_waiting_time) {
        cout << "\nAfter Comparing all the algorithms, we can evaluate that SJF has the best average waiting time........" << endl;
    }
    else if (minimum_avgwt == RR_average_waiting_time) {
        cout << "\nAfter Comparing all the algorithms, we can evaluate that RR has the best average waiting time........" << endl;
    }
    else {
        cout << "\nAfter Comparing all the algorithms, we can evaluate that PS has the best average waiting time........" << endl;
    }
}

int main() {
    int choice;
    while (true) {

        system("cls");  
        cout << "-------------------\n";
        cout << "USER INTERFACE\n";
        cout << "-------------------\n";
        cout << "1. Scheduling Algorithm\n";
        cout << "2. Algorithm Evaluator\n";
        cout << "3. Exit the program\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            cout << "---------------------\n";
            cout << "SCHEDULING ALGORITHMS\n";
            cout << "---------------------\n";
            cout << "1. FCFS (First Come First Serve)\n";
            cout << "2. SJF (Shortest Job First)\n";
            cout << "3. RR (Round Robin)\n";
            cout << "4. PS (Priority Scheduling)\n";
            cout << "\nEnter your choice: ";
            cin >> choice;

            if (choice >= 1 && choice <= 4) {
                system("cls");

                int n;
                cout << "How many processes: ";
                cin >> n;
                while (n <= 0 || cin.fail()) {

                    cin.clear();  
                    cin.ignore();  

                    cout << "Process should be greater than 0.\nEnter the processes again: ";
                    cin >> n;
                }

                Process process[n];
                bool is_priority = (choice == 4);
                takeInput(process, n, is_priority);

                switch (choice) {
                    case 1:
                        FCFS(n, process);
                        break;
                    case 2:
                        SJF(n, process);
                        break;
                    case 3: {

                        int quantum;
                        cout << "\nEnter time quantum: ";
                        cin >> quantum;

                    while (quantum <= 0 || cin.fail()) {

                        cin.clear();  
                        cin.ignore();  

                        cout << "Time Quantum should be greater than 0.\nEnter time quantum again: ";
                        cin >> quantum;
                    }
                        RoundRobin(n, process, quantum);
                        break;
                    }
                    case 4:
                        PriorityScheduling(n, process);
                        break;
                }
            } 
            else {
                cout << "Invalid choice. Please select a valid algorithm.\n";
            }
        } 
        else if (choice == 2) {
         
            EvaluateAlgorithms();
        } 
        else if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        } 
        else {
            cout << "Invalid choice. Please enter a valid option.\n";
        }

        cout << "\nPress any key to continue...";
        cin.ignore();
        cin.get();
    }
    return 0;
}
