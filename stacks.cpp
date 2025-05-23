#include <iostream>
#include <cstdlib>
using namespace std;

char stack[100];
int top = -1;

void push(char x)
{
    stack[top++] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    else
        stack[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;

    return 0;
}

int main()
{
    char exp[100];
    char *e, x;

    cout << "Enter the expression: ";
    cin >> exp;

    e = exp;

    while(*e != '\0')
    {
        if( isalnum(*e) )
            cout << *e;
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while((x = pop()) != '(')
                cout << x;
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
            {
                cout << pop();
                push(*e);
            }
            e++;
        }
    }
    while(top != -1)
    {
        cout << pop();
    }
    return 0;;
}
