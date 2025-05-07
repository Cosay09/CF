#include <stdio.h>

#define size 100

int queue[size];
int front = -1, rear = -1;

void enqueue(int val)
{
   if (rear == size - 1)
      printf("Queue is full\n");
   else
   {
      if (front == -1)
         front = 0;
      queue[++rear] = val;
      printf("Enqueued: %d\n", val);
   }
}

void dequeue()
{
   if (front == -1 || front > rear)
      printf("Queue is empty\n");
   else
      printf("Dequeued: %d\n", queue[front++]);
}

void display()
{
   if (front == -1 || front > rear)
      printf("Queue is empty\n");
   else
   {
      printf("Queue: ");
      for (int i = front; i <= rear; i++)
         printf("%d ", queue[i]);
      printf("\n");
   }
}

int main()
{
   enqueue(10);
   enqueue(20);
   enqueue(30);

   display();

   dequeue();

   display();

   enqueue(40);

   display();

   return 0;
}


