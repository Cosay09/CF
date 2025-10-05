//Input the processes along with their cputime and arrivaltime
//Find waiting time (wt) for all processes.
//As the first process comes in and do not need to wait; waiting time for process 0 will be 0
//i.e. waitingtime [0] = 0.
//Find waiting time for all other processes i.e. for
//process i ;
//waitingtime[i] = cputime[i-1] + waitingtime [i-1] – arrivaltime[i].
//Find turnaround time[i] = waiting_time [i] + cputime[i]
//for all processes.
//Find average waiting time =
//total_waiting_time / no_of_processes.
//Similarly, find average turnaround time =
//total_turn_around_time / no_of_processes.

#include <bits/stdc++.h>
using namespace std;

class process
{
 public:
    int CPU_time;
    int Arrival_time;

    process(int CPU_time = 0, int Arrival_time = 0)
    {
        this->CPU_time = CPU_time;
        this->Arrival_time = Arrival_time;
    }

    void CPU_t()
    {
        cin >> CPU_time;
    }

    void Arrival_t()
    {
        cin >> Arrival_time;
    }

    void display() const
    {
        cout << "CPU Time: " << CPU_time << ", Arrival Time: " << Arrival_time << endl;
    }
};

int main()
{
    int num_process;
    cout << "Enter number of process: ";
    cin >> num_process;

    vector<process> processes(num_process);

    cout << "Enter the CPU times: \n";

    //Enters CPU time
    for (int i = 0; i < num_process; i++)
    {
        processes[i].CPU_t();
    }

    cout << "Enter Arrival times: \n";

    //Enters Arrical time
    for (int i = 0; i < num_process; i++)
    {
        processes[i].Arrival_t();
    }

    cout << "\n";

    sort(processes.begin(), processes.end(), [](process a, process b)
         { return a.Arrival_time < b.Arrival_time; });

    int waiting_time[num_process], turnaround_time[num_process];
    waiting_time[0] = 0;

    for (int i = 1; i < num_process; i++)
    {
        waiting_time[i] = (processes[i - 1].CPU_time + waiting_time[i - 1]) - processes[i].Arrival_time;
            if (waiting_time[i] < 0) // CPU was idle before this process
                waiting_time[i] = 0;
    }

    for (int i = 0; i < num_process; i++)
        turnaround_time[i] = waiting_time[i] + processes[i].CPU_time;

    for (int i = 0; i < num_process; i++)
    {
        cout << "Process " << i+1 << ": Waiting Time: " << waiting_time[i] << " Turnaround Time: " << turnaround_time[i] << "\n";
    }

    float avg_waiting = 0.0f;
    float avg_turnaround = 0.0f;
    for (int i =0; i < num_process; i++)
    {
        avg_turnaround += turnaround_time[i];
        avg_waiting += waiting_time[i];
    }

    cout << "\n";
    cout << "Average Waiting time: " << avg_waiting/num_process << "\nAverage Turnaround time: " << avg_turnaround/num_process << "\n";

    return 0;
}
