/* Online C Compiler and Editor */
#include <stdio.h>
#include <stdlib.h>

#define RED_BOLD "\x1b[;31;1m"
#define BLU_BOLD "\x1b[;34;1m"
#define YEL_BOLD "\x1b[;33;1m"
#define GRN_BOLD "\x1b[;32;1m"
#define CYAN_BOLD_ITALIC "\x1b[;36;1;3m"
#define RESET "\x1b[0;m"

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* rear;
Node* front;
int size = 0;
Node* enqueue(Node* Queue, int data);
Node* dequeue(Node* Queue);
int IsQueueEmpty();
int IsQueueFull();//No used
void Print_Queue(Node* Queue);
void Test_Queue(Node* Queue);

int IsQueueEmpty()
{
    if(size > 0)
        return 0;
    else
        return 1;
}
void Print_Queue(Node* Queue)
{
    Node* Node_Ptr = Queue;

    printf(YEL_BOLD"Queue: ");
    if(!IsQueueEmpty())
    {
        while(Node_Ptr)
        {
            printf("[%d] ",Node_Ptr->data);
            Node_Ptr = Node_Ptr->next;
        }printf("\n\n");        
    }
    else
    {
        printf("Empty\n\n"RESET);
    }
}
Node* dequeue(Node* Queue)
{
    Node* Node_Ptr = front;

    if(!IsQueueEmpty())
    {
        printf(RED_BOLD"dequeue [%d]\n"RESET,front->data);
        if(front == rear)
        {
            front = NULL;
            rear = NULL;
            
            free(front);
        }
        else
        {
            front=front->next;
            
            free(Node_Ptr);        
            
        }
        size--;     
    }
    else //empty
    {
        printf("Queue Empty, Can't dequeue.\n");
    }
    return front;
}

Node* enqueue(Node* Queue, int data)
{
    Node* Node_Ptr = (Node *)malloc(sizeof(Node));

    Node_Ptr->data = data;
    Node_Ptr->next = NULL;  
    size++;

    if(Queue == NULL)
    {
        Queue = Node_Ptr;
        rear = Node_Ptr;
        front = Node_Ptr;
    }
    else
    {
        rear->next = Node_Ptr;
        rear = Node_Ptr;
    }
    printf(RED_BOLD"enqueue [%d]\n"RESET,rear->data);
    return Queue;
}

void Test_Queue(Node* queue)
{
	queue = enqueue(queue, 1);
    queue = enqueue(queue, 2);
    queue = enqueue(queue, 3);
    queue = enqueue(queue, 4);

    Print_Queue(queue);
    queue = dequeue(queue);
    Print_Queue(queue);
    queue = dequeue(queue);
    Print_Queue(queue);
    queue = enqueue(queue, 5);
    queue = enqueue(queue, 6);
    Print_Queue(queue);
    queue = dequeue(queue);
    queue = dequeue(queue);

    queue = dequeue(queue);
    queue = dequeue(queue);
    queue = enqueue(queue, 7);
    Print_Queue(queue);
    queue = enqueue(queue, 8);   
    Print_Queue(queue);
    queue = dequeue(queue);
    Print_Queue(queue);
    queue = dequeue(queue);

    queue = dequeue(queue);
    Print_Queue(queue);
    queue = dequeue(queue);
    Print_Queue(queue);
    queue = dequeue(queue);
    Print_Queue(queue);
    queue = dequeue(queue);
    Print_Queue(queue);
    queue = enqueue(queue, 1);
    Print_Queue(queue);
    queue = enqueue(queue, 2);
    Print_Queue(queue);
    queue = enqueue(queue, 3);
    Print_Queue(queue);
    queue = dequeue(queue);
    Print_Queue(queue);    
    queue = enqueue(queue, 4);
    Print_Queue(queue);
    queue = dequeue(queue);
    Print_Queue(queue);    
    queue = dequeue(queue);
    Print_Queue(queue);    
    queue = dequeue(queue);
    Print_Queue(queue);
    queue = dequeue(queue);
    Print_Queue(queue);
    queue = dequeue(queue);
    Print_Queue(queue);
}
int main()
{
    printf("Hello, Queue v2!\n");
    Node *queue = NULL;

	Test_Queue(queue);

    return 0;
}