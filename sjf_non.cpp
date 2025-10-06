#include <bits/stdc++.h>
using namespace std;

class process {
  public:
    int CPU_time;
    int Arrival_time;
    int waiting_time;
    int turnaround_time;
    bool completed;

    process(int CPU_time = 0, int Arrival_time = 0)
    {
        this->CPU_time = CPU_time;
        this->Arrival_time = Arrival_time;
        waiting_time = 0;
        turnaround_time = 0;
        completed = false;
    }

    void CPU_t()
    {
        cin >> CPU_time;
    }
    void Arrival_t()
    {
        cin >> Arrival_time;
    }
};

int main()
{
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

    // Sort by arrival time first
    sort(processes.begin(), processes.end(),
         [](process &a, process &b) { return a.Arrival_time < b.Arrival_time; });

    while (completed < num_process)
    {
        int idx = -1;
        int minBurst = INT_MAX;

        // Select process with min CPU time among arrived ones
        for (int i = 0; i < num_process; i++)
        {
            if (!processes[i].completed && processes[i].Arrival_time <= timer)
            {
                if (processes[i].CPU_time < minBurst)
                {
                    minBurst = processes[i].CPU_time;
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            timer++;
            continue;
        }

        // Execute the process
        timer += processes[idx].CPU_time;
        processes[idx].completed = true;
        completed++;

        processes[idx].turnaround_time = timer - processes[idx].Arrival_time;
        processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].CPU_time;
    }

    float avg_waiting = 0.0f, avg_turnaround = 0.0f;
    cout << "\nProcess details:\n";
    for (int i = 0; i < num_process; i++)
    {
        cout << "Process " << i + 1 << ": Waiting Time: " << processes[i].waiting_time
             << " Turnaround Time: " << processes[i].turnaround_time << "\n";
    }
    for (int i = 0; i < num_process; i++)
    {
        avg_waiting += processes[i].waiting_time;
        avg_turnaround += processes[i].turnaround_time;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting time: " << avg_waiting / num_process
         << "\nAverage Turnaround time: " << avg_turnaround / num_process << "\n";
}
