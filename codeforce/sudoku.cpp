#include <bits/stdc++.h>
using namespace std;

bool checkRows(int A[9][9]);
bool checkcolumns(int A[9][9]);
bool checkBoxes(int A[9][9]);

int main()
{
    int A[9][9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> A[i][j];
        }
    }

    if (checkBoxes(A) && checkRows(A) && checkcolumns(A))
    {
        cout << "YES";
    }
    else
        cout << "NO";
}

bool checkRows(int A[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        bool seen[10] = {false};
        for (int j = 0; j < 9; j++)
        {
            int val = A[i][j];
            if (seen[val])
                return false;
            seen[val] = true;
        }
    }
    return true;
}

bool checkcolumns(int A[9][9])
{
    for (int j = 0; j < 9; j++)
    {
        bool seen[10] = {false};
        for (int i = 0; i < 9; i++)
        {
            int val = A[j][i];
            if (seen[val])
                return false;
            seen[val] = true;
        }
    }
    return true;
}

bool checkBoxes(int A[9][9])
{
    for (int boxRow = 0; boxRow < 3; boxRow++)
    {
        for (int boxCol = 0; boxCol < 3; boxCol++)
        {
            bool seen[10] = {false};
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int val = A[boxRow * 3 + i][boxCol * 3 + j];
                    if (val < 1 || val > 9 || seen[val])
                        return false;
                    seen[val] = true;
                }
            }
        }
    }
    return true;
}
