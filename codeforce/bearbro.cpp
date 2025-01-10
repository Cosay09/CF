#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int years = INT_MAX;
    if (n == m)
    {
        cout << "1";
        return 0;
    }
    else
    {
        for (int i = 1; n <= m; i++)
        {
            n *= 3;
            m *= 2;
            years = i;
        }
        cout << years;
    }
}