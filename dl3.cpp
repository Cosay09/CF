#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter the no. of processes: ";
    cin >> n;
    cout << "Enter the no. of resources: ";
    cin >> m;

    int maxNeed[n][m], allocation[n][m], need[n][m];
    int available[m];

    for (int i = 0; i < n; i++) {
        cout << "\nProcess " << i + 1 << ":\n";
        for (int j = 0; j < m; j++) {
            cout << "  Maximum value for resource " << j + 1 << ": ";
            cin >> maxNeed[i][j];
        }
        for (int j = 0; j < m; j++) {
            cout << "  Allocated from resource " << j + 1 << ": ";
            cin >> allocation[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        cout << "\nEnter total value of resource: " << j + 1 << "\n";
        cin >> available[j];
    }

    // Compute Need = Max - Allocation
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxNeed[i][j] - allocation[i][j];

    // Safety algorithm
    bool finish[n] = {false};
    int safeSeq[n], count = 0;

    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                bool canRun = true;
                for (int j = 0; j < m; j++) {
                    if (need[p][j] > available[j]) {
                        canRun = false;
                        break;
                    }
                }
                if (canRun) {
                    for (int j = 0; j < m; j++)
                        available[j] += allocation[p][j];
                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "\nSystem is NOT in a safe state.\n";
            return 0;
        }
    }

    cout << "\nThe System is currently in a safe state.\n";
    cout << "< ";
    for (int i = 0; i < n; i++) {
        cout << "P" << safeSeq[i] + 1;
        if (i != n - 1) cout << " ";
    }
    cout << " > is the safe sequence.\n";

    return 0;
}
