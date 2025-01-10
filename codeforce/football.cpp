#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    int cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        for (int j = i; j < s.length(); j++)
        {
            if (s[j] == c)
            {
                cnt++;
                i = j;
                if (cnt == 7)
                {
                    cout << "YES" << endl;
                    goto hell;
                }
            }
            else
            {
                cnt = 0;
                i = j - 1;
                break;
            }
        }
    }
    cout << "NO" << endl;
    hell:;
}