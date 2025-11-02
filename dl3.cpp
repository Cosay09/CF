#include <iostream>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter the no. of processes: ";
    cin >> n;
    cout << "Enter the no. of resources: ";
    cin >> m;

    int maxNeed[n][m], allocation[n][m], need[n][m];
    int available[m];

    for (int i = 0; i < n; i++)
    {
        cout << "\nProcess " << i + 1 << "\n";
        for (int j = 0; j < m; j++)
        {
            cout << "  Maximum value for resource " << j + 1 << ": ";
            cin >> maxNeed[i][j];
        }
        for (int j = 0; j < m; j++)
        {
            cout << "  Allocated from resource " << j + 1 << ": ";
            cin >> allocation[i][j];
        }
    }

    cout << "\nEnter total available instances of each resource:\n";
    for (int j = 0; j < m; j++)
    {
        cout << " Resource " << j + 1 << ": ";
        cin >> available[j];
    }

    // Compute Need = Max - Allocation
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxNeed[i][j] - allocation[i][j];

    int work[m];
    bool finish[n] = {false};

    for (int j = 0; j < m; j++)
        work[j] = available[j];

    int safeSeq[n];
    int count = 0;

    // Step 2: Find an unfinished process whose Need <= Work
    while (count < n)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                bool canAllocate = true;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canAllocate = false;
                        break;
                    }
                }

                // Step 3: If found, allocate resources temporarily
                if (canAllocate)
                {
                    for (int j = 0; j < m; j++)
                        work[j] += allocation[i][j];
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        // Step 4: If no such process is found — unsafe state
        if (!found)
        {
            cout << "\nSystem is NOT in a safe state.\n";
            return 0;
        }
    }

    // Step 5: If all processes finished safely
    cout << "\nThe System is currently in a safe state.\n";
    cout << "< ";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << safeSeq[i] + 1;
        if (i != n - 1)
            cout << " ";
    }
    cout << " > is the safe sequence.\n";

    return 0;
}
