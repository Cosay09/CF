#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    double xmin = min(min(x1, x3), min(x2, x4));
    double xmax = max(max(x1, x3), max(x2, x4));
    double ymin = min(min(y1, y3), min(y2, y4));
    double ymax = max(max(y1, y3), max(y2, y4));

    int n; 
    cin >> n;
    
    while (n--)
    {
        double x, y;
        cin >> x >> y;

        if ((x >= xmin && x <= xmax) && (y >= ymin && y <= ymax))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}