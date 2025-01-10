#include <bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, b, c;
        cin >> n >> b >> c;
        if (n==b && n== c)
        {
            cout << n << endl;
        }
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            A[i] = b * i + c;
        }

        set<int> s(A.begin(), A.end());
        if (s.size() == n && *s.begin() == 0 && *s.rbegin() == n - 1)
        {
            cout << 0 << endl;
        }
        else
        {
            bool possible = true;
            vector<int> transformed(n, -1);
            for (int i = 0; i < n; i++)
            {
                int val = A[i];
                if (val >= 0 && val < n && transformed[val] == -1)
                {
                    transformed[val] = i;
                }
                else
                {
                    possible = false;
                    break;
                }
            }

            if (possible)
            {
                cout << 0 << endl;
            }
            else
            {
                int operations = 0;
                vector<int> target(n);
                for (int i = 0; i < n; i++)
                {
                    target[i] = i;
                }

                vector<bool> visited(n, false);
                for (int i = 0; i < n; i++)
                {
                    if (!visited[i])
                    {
                        int j = i;
                        while (!visited[j])
                        {
                            visited[j] = true;
                            j = A[j] % n;
                        }
                        operations++;
                    }
                }

                cout << operations << endl;
                
            }
        }
    }
}
