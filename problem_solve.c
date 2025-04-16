#include <stdio.h>

#define MAXSIZE 8

int stack[MAXSIZE];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAXSIZE - 1;
}

int peek()
{
    if (!isEmpty())
        return stack[top];
    else
    {
        printf("Stack is empty.\n");
        return -1;
    }
}

int pop()
{
    if (!isEmpty())
    {
        int data = stack[top];
        top--;
        return data;
    }
    else
    {
        printf("Could not retrieve data, stack is empty.\n");
        return -1;
    }
}

void push(int data)
{
    if (!isFull())
    {
        top++;
        stack[top] = data;
    }
    else
    {
        printf("Could not insert data, stack is full.\n");
    }
}

int main()
{
    push(3);
    push(5);
    push(9);
    push(1);
    push(12);
    push(15);

    printf("Element at top of the stack: %d\n", peek());

    printf("Elements:\n");
    while (!isEmpty())
    {
        int data = pop();
        printf("%d\n", data);
    }

    printf("Stack full: %s\n", isFull() ? "true" : "false");
    printf("Stack empty: %s\n", isEmpty() ? "true" : "false");

    return 0;
}

