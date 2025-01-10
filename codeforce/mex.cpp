#include <bits/stdc++.h>
using namespace std;;

#define endl '\n'
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int main()
{
    optimize();
    int t; cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        if (n > m) cout << n + 1 << endl;
        else cout << m + 1 << endl;
    }
}