#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int main()
{
    optimize();
    int t;
    for (cin >> t; t-->0;)
    {
        int n, k, a;
        set<int> B;
        map<int, int> A;

        for (cin >> n >> k; n --> 0;)
            cin >> a; A[a]++;

        int size = B.size();
        vector<int> C;

        for (auto i: A)
            C.push_back(i.second);
        
        sort(C.begin(), C.end());

        for (auto i: C)
        {
            if (i <= k)
            {
                size--;
                k -= i;
            }
            else
                break;
        }

        if (size <= 1) cout << 1;
        else cout << size << '\n';
    }
}