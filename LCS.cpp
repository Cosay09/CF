#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

string lcs(const string &X, const string &Y)
{
    int m = X.size();
    int n = Y.size();
    int c[MAX][MAX] = {0};
    char b[MAX][MAX] = {0};

    // Fill c and b tables
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'd'; // diagonal
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u'; // up
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l'; // left
            }
        }
    }

    // Reconstruct LCS from b table
    string lcs_str;
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (b[i][j] == 'd')
        {
            lcs_str = X[i - 1] + lcs_str;
            --i;
            --j;
        }
        else if (b[i][j] == 'u')
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    return lcs_str;
}

int main()
{
    string X, Y;
    cout << "Enter first string: ";
    
    cin >> X;
    cout << "Enter second string: ";
    
    cin >> Y;
    string result = lcs(X, Y);
    cout << "Longest Common Subsequence: " << result << endl;
}
