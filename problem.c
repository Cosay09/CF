#include<stdio.h>

int MAXSIZE=8;
int stack[8];
int top= -1;

int is empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isfull()
{

    if(top==MAXSIZE)
        return 1;
    else
        return 0;

}
int peek()
{
    return stack[top];
}
int pop()
{

    int data;

    if(!isempty())
    {
        data=stack[top];
        top=top-1;

        return data;
    }
    else
    {
        printf("could not retrive data,stack is empty.\n");
    }
}

int push(int data)
{
    if (!isfull())
    {
        stack[top] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full\n");
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

    printf("element at top of the stack:%d\n",peek());
    printf("elements:\n");


    while(!isempty())
    {
        int data=pop();
        printf("%d\n",data);

    }
    printf("stack full:%s\n",isfull()?"true":"false");
    printf("stack empty:%s\n",isempty()?"true":"false");

    return 0;
}

}
