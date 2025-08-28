#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

void ebrc(int p[], int n, int r[], int s[])
{
    r[0] = 0;

    for (int i = 0; i <= n; i++)
    {
        int q = -1;
        for (int j = 1; j <= i; j++)
        {
            if (q < p[j] + r[i - j])
            {
                q = p[j] + r[i - j];
                s[i] = j;
            }
        }
        r[i] = q;
        cout << "r array: " << r[i] << endl;
    }
}

void print(int s[], int n)
{
    cout << "Number of cuts: ";

    while (n > 0)
    {
        cout << s[n] << " ";
        n = n - s[n];
    }
}

int main()
{
    int n = 10;

    int p[MAX] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int r[MAX] = {0};
    int s[MAX] = {0};

    ebrc(p, n, r, s);

    cout << "Maximimum revinue: " << r[n] << endl;
    print(s, n);

    cout << endl;
}
