#include <iostream>
#include <cstdlib>
using namespace std;

const int stack_size = 8;
int stack[stack_size];
int top = -1;

bool stack_is_empty()
{
    return (top == -1);
}

bool stack_is_full()
{
    return (top == stack_size - 1);
}

void push(int value)
{
    if (!stack_is_full())
    {
        top++;
        stack[top] = value;
    }
    else
    {
        cout << "Stack is Full!" << endl;
    }
}

void pop()
{
    if (!stack_is_empty())
    {
        top--;
    }
    else
    {
        cout << "Stack is Empty!" << endl;
    }
}

void peek()
{
    if (!stack_is_empty())
    {
        cout << stack[top] << endl;
    }
    else
    {
        cout << "Stack is Empty!" << endl;
    }
}

int main()
{
    cout << "Randomly Generated stack: " << endl;
    while (!stack_is_full())
    {
        push(rand() % 10);
    }

    for (int i = 0; i <= top; i++)
    {
        cout << "Stack[" << i << "] = " << stack[i] << endl;
    }

    cout << "Stack Top: " << endl;
    peek();

    cout << "POP! POP!: " << endl;
    pop();
    pop();

    cout << "Stack After Popping Two Elements:" << endl;
    for (int i = 0; i <= top; i++)
    {
        cout << "Stack[" << i << "] = " << stack[i] << endl;
    }

    cout << "Stack Top After Popping:" << endl;
    peek();

    return 0;
}
