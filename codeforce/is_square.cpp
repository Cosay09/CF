#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            total += A[i];
        }

        int i = 2;
        bool flag = false;

        while (i*i <= total)
        {
            if (pow(i, 2) == total)
            {
                cout << "YES" << endl;
                flag = true;
                break;
            }
            i++;
        }

        if (!flag)
        {
            cout << "NO" << endl;
        }
    }
}