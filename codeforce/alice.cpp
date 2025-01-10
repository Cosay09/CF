#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, qx, qy;
        cin >> n >> qx >> qy;
        string s; cin >> s;
        
        int x = 0, y = 0;
        bool found = false;
        
        for (int i = 0; i < 15; ++i)
        {
            for (char move : s)
            {
                if (move == 'N') y++;
                else if (move == 'E') x++;
                else if (move == 'S') y--;
                else if (move == 'W') x--;
                
                if (x == qx && y == qy)
                {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        
        if (found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
