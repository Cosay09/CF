#include<bits/stdc++.h>
using namespace std;

int binary (int arr[], int x, int left, int right)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort (A, A + N);
    while (Q--)
    {
        int X;
        cin >> X;
        int found = binary(A, X, 0, N - 1);

        if (found == -1)
        {
            cout << "not found" << endl;
        }
        else
        {
            cout << "found" << endl;
        }
    }
}
/*
#include<bits/stdc++.h>
using namespace std;
                                  // 0        4
int binary (int arr[], int x, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    if (arr[mid] > x)
    {
        return binary(arr, x, start, mid - 1);
    }
    return binary(arr, x, mid + 1, end);
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort (A, A + N);
    while (Q--)
    {
        int X;
        cin >> X;
        int found = binary(A, X, 0, N - 1);

        if (found == -1)
        {
            cout << "not found" << endl;
        }
        else
        {
            cout << "found" << endl;
        }
    }
}
*/