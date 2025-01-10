#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[5][5];
    int row = INT_MAX, col = INT_MAX;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 1)
            {
                row = i;
                col = j;
            }
        }
    }
    //cout << row << " " << col << endl;
    int count = 0;
    if (col == 2 && row == 2)
    {
        //cout << "Executed" << endl;
        cout << "0";
        return 0;
    }
    while (row != 2 or col != 2)
    {
        //cout << "Running" << endl;
        if (row > 2)
        {
            row--;
            count++;
        }
        if (row < 2)
        {
            row++; // row = 1+1 = 2
            //cout << "Row = " << row << endl;
            count++;
            //cout << "Count = " << count << endl;
        }
        if (col > 2)
        {
            col--;
            count++;
        }
        if (col < 2)
        {
            col++;
            //cout << "Col = " << col << endl;
            count++;
            //cout << "Count = " << count << endl;
        }
    }
    cout << count;
}