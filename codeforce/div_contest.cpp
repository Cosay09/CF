#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int legs;
        cin >> legs;
        int animals = 0;

        if (legs / 4 != 0)
        {
            animals += legs / 4;
            legs = legs % 4;
        }
        if (legs / 2 != 0)
        {
            animals += legs / 2;
            legs = legs % 2;
        }
        cout << animals << endl;
    }
}