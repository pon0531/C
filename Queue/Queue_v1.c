/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#define RED_BOLD "\x1b[;31;1m"
#define BLU_BOLD "\x1b[;34;1m"
#define YEL_BOLD "\x1b[;33;1m"
#define GRN_BOLD "\x1b[;32;1m"
#define CYAN_BOLD_ITALIC "\x1b[;36;1;3m"
#define RESET "\x1b[0;m"
#define DEBUG printf("%s, front[%d], rear[%d], size[%d]\n",__func__, front,rear,size);

#define MAXSIZE 10
int rear = -1;
int front = -1;
int size = -1;

int enqueue(int* Queue, int data);
int dequeue(int* Queue);
int IsQueueEmpty();//No used
int IsQueueFull();//No used
void Print_Queue(int* Queue);
void Test_Queue(int* Queue);

int IsQueueEmpty()
{
    if((front != 0) && (front == rear))
        return 1;
    else
        return 0;
}

int IsQueueFull()
{
    if((rear != 0) && (front == rear))
        return 1;
    else
        return 0;
}

int enqueue(int* Queue, int data)
{
    DEBUG
    if(size < MAXSIZE)
    {
        printf(RED_BOLD"Queue enqueue [%d]\n"RESET,data);
        if(size < 0) //when Queue empty, reset to Queue[0]
        {
            Queue[0] = data;
            front = rear = 0;
            size = 1;
        }
        else if(rear == MAXSIZE -1)
        {
            Queue[0] = data;
            rear = 0;
            size++;
        }
        else
        {
            Queue[rear+1] = data;
            rear++;
            size++;
        }
    }
    else
    {
        printf("Queue is full\n");
    }
}

int dequeue(int* Queue)
{
    DEBUG
    if(size < 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf(RED_BOLD"Queue dequeue [%d]\n"RESET,Queue[front]);
        
        size--;
        front++;
    }
}
void Print_Queue(int* Queue)
{
    DEBUG
    printf(YEL_BOLD"Queue: ");
    for(int i = front;i<=rear;i++)
        printf("[%d] ", Queue[i]);
    printf("\n\n"RESET);
}

void Test_Queue(int* Queue)
{
    enqueue(Queue, 3);
    enqueue(Queue, 4);
    enqueue(Queue, 5);
    enqueue(Queue, 6);
    Print_Queue(Queue);
    
    dequeue(Queue);
    Print_Queue(Queue);
    dequeue(Queue);
    Print_Queue(Queue);
    dequeue(Queue);
    Print_Queue(Queue);
    dequeue(Queue);
    Print_Queue(Queue);
    dequeue(Queue);
    Print_Queue(Queue);

    dequeue(Queue);
    Print_Queue(Queue);
    dequeue(Queue);
    Print_Queue(Queue);
    dequeue(Queue);
    Print_Queue(Queue);
    enqueue(Queue, 3);
    enqueue(Queue, 4);
    enqueue(Queue, 5);
    enqueue(Queue, 6);
    Print_Queue(Queue);
    enqueue(Queue, 7);
    enqueue(Queue, 8);
    enqueue(Queue, 9);
    enqueue(Queue, 10);
    enqueue(Queue, 11);
    enqueue(Queue, 12);
    Print_Queue(Queue);
    enqueue(Queue, 13);
    enqueue(Queue, 14);
}

int main()
{
    printf("Hello Queue v1 (Array version)\n");
    
    int Queue[MAXSIZE];
    for(int i = 0; i < size;i++)
        Queue[i] = 0;

    Test_Queue(Queue);

    return 0;
}
