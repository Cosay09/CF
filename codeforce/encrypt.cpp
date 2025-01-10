// Sheet 4: Strings
// Q: Encrypt & Decrypt Message
// Key = "PgEfTYaWGHjDAmxQqFLRpCJBownyUKZXkbvzIdshurMilNSVOtec#@_!=.+-*/"
// Original = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string key = "PgEfTYaWGHjDAmxQqFLRpCJBownyUKZXkbvzIdshurMilNSVOtec#@_!=.+-*/";
    string org = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int size = org.size();

    int N;
    cin >> N;
    string S;
    cin >> S;
    int length = S.size();

    if (N == 1)
    {
        for (int i = 0; i < length; i++)
        {
            char c = S[i];
            for (int j = 0; j < size; j++)
            {
                if (c == org[j])
                {
                    cout << key[j];
                    break;
                }
            }
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            char c = S[i];
            for (int j = 0; j < size; j++)
            {
                if (c == key[j])
                {
                    cout << org[j];
                    break;
                }
            }
        }
        cout << endl;
    }
}