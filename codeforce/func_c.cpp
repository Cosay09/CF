#include <bits/stdc++.h>
using namespace std;

int ispalindrome (int arr[], int N) // binary[], i = 2
{
    int end = N - 1; // 1
    for (int i = 0; i < N/2; i++) // N/2 = 1
    {
        if (arr[i] != arr[end]) // arr[0] != arr[1]
        {
            return 1;
        }
        end--;
    }
    return 0; // yes
}
int isodd(int odd)
{
    if (odd % 2 != 0) //is odd 3 % 2 = 1
    {
        return 0; //returns
    }
    return 1; // not odd
}

int main()
{
    int N;
    cin >> N;
    int r_N = N;
    int binary[100];
    int i = 0;
    while (N != 0)
    {
        binary[i] = N % 2;
        cout << binary[i];
        N = N / 2;
        i++;
    }
    cout << endl;
    binary[i] = '\0';

    int palindrome = ispalindrome(binary, i);
    int odd = isodd(r_N);
    cout << "pal = " << palindrome << endl << "odd = " << odd << endl;

    if (odd == 0 && palindrome == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

/*#include <bits/stdc++.h>
using namespace std;

int palindrome(int arr[], int N)
{
    int end = N - 1;
    for (int i = 0; i < N/2; i++)
    {
        if (arr[i] != arr[end])
        {
            return 1;
        }
        end--;
    }
    return 0;
}

int main()
{
    int a;
    cin >> a;
    int A[a];
    for (int i = 0; i < a; i++)
    {
        cin >> A[i];
    }
    int ispal = palindrome(A,a);
    if (ispal == 1)
    {
        cout << "NO" << endl;
    }
    else if (ispal == 0)
    {
        cout << "YES" << endl;
    }
}
*/