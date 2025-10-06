#include <bits/stdc++.h>
using namespace std;

class process {
public:
    int CPU_time;
    int Arrival_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
    bool completed;

    process(int CPU_time = 0, int Arrival_time = 0) {
        this->CPU_time = CPU_time;
        this->Arrival_time = Arrival_time;
        waiting_time = 0;
        turnaround_time = 0;
        remaining_time = CPU_time;
        completed = false;
    }

    void CPU_t() { cin >> CPU_time; remaining_time = CPU_time; }
    void Arrival_t() { cin >> Arrival_time; }
};

int main() {
    int num_process;
    cout << "Enter number of process: \n";
    cin >> num_process;

    vector<process> processes(num_process);

    cout << "Enter the CPU times: \n";
    for (int i = 0; i < num_process; i++)
        processes[i].CPU_t();

    cout << "Enter Arrival times: \n";
    for (int i = 0; i < num_process; i++)
        processes[i].Arrival_t();

    int completed = 0;
    int timer = 0;
    int prev = -1;
    float avg_waiting = 0.0f, avg_turnaround = 0.0f;

    // Sort by arrival time
    sort(processes.begin(), processes.end(),
         [](process &a, process &b) { return a.Arrival_time < b.Arrival_time; });

    while (completed < num_process) {
        int idx = -1;
        int minRem = INT_MAX;

        // Find process with minimum remaining time among arrived
        for (int i = 0; i < num_process; i++) {
            if (processes[i].Arrival_time <= timer && !processes[i].completed) {
                if (processes[i].remaining_time < minRem) {
                    minRem = processes[i].remaining_time;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            processes[idx].remaining_time--;
            timer++;

            // If process finishes
            if (processes[idx].remaining_time == 0) {
                processes[idx].completed = true;
                completed++;
                processes[idx].turnaround_time = timer - processes[idx].Arrival_time;
                processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].CPU_time;
            }
        } else {
            // If no process has arrived yet
            timer++;
        }
    }

    cout << "\nProcess details:\n";
    for (int i = 0; i < num_process; i++) {
        cout << "Process " << i + 1
             << ": Waiting Time: " << processes[i].waiting_time
             << ", Turnaround Time: " << processes[i].turnaround_time << "\n";
        avg_waiting += processes[i].waiting_time;
        avg_turnaround += processes[i].turnaround_time;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting time: " << avg_waiting / num_process
         << "\nAverage Turnaround time: " << avg_turnaround / num_process << "\n";
}
