#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int A[n][3];
    int ix = 0, jy = 0, kz = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                ix += A[i][j];
            }
            else if (j == 1)
            {
                jy += A[i][j];
            }
            else
            {
                kz += A[i][j];
            }
        }
    }
    if ((ix == 0 && jy == 0) && kz == 0) cout << "YES";
    else cout << "NO";
    
}