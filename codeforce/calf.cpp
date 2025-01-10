#include <bits/stdc++.h>
using namespace std;

#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        long long n; cin >> n;

        if (n == 1)
        {
            cout << 2 << endl;
        }
        else if (n == 2)
        {
            cout << 1 << endl;
        }
        else if (n % 3 == 0)
        {
            cout << n / 3 << endl;
        }
        else if (n % 3 == 1)
        {
            cout << ((n / 3 ) + 1) << endl;
        }
        else if (n % 3 == 2)
        {
            cout << ((n / 3) + 1) << endl;
        }
    }
}