#include <iostream>
using namespace std;

int main() {
    int start[]  = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int finish[] = {4, 5, 6, 7, 9, 9, 10,11,12,14,16};
    int n = sizeof(start) / sizeof(start[0]);

    int selectedIndices[n];
    int count = 0;

    // Select first activity
    selectedIndices[count++] = 0;
    int k = 0;

    for (int m = 1; m < n; m++) {
        if (start[m] >= finish[k]) {
            selectedIndices[count++] = m;
            k = m;
        }
    }

    cout << "Selected activities: ";
    for (int i = 0; i < count; i++) {
        int idx = selectedIndices[i];
        cout << "(" << start[idx] << "," << finish[idx] << ") ";
    }
    cout << endl;

    return 0;
}
