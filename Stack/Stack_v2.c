#include <stdlib.h>
#include <stdio.h>

#if 0 // 2 types of struct define
struct node{
    int data;
    struct node* next;
};
typedef struct node Node;
#else
typedef struct node {
    int data;
    struct node* next;
}Node;
#endif

int StackIsFull(Node *top)
{
    //No need to check full when stack use linked list
    return 1;
}
int StackIsEmpty(Node *top)
{
    if(top == NULL)
    {
        printf("Stack Empty! Can't pop.\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void Stack_Print(Node *top)
{
    Node * Node_ptr = top;

    printf("Stack(top): ");
#if 1
    while(Node_ptr != NULL)
    {
        printf("[%d] ", Node_ptr->data);
        Node_ptr = Node_ptr->next;
    }
    printf("\n");
#else
    if(Node_ptr == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("[%d] ", Node_ptr->data);
        Stack_Print(Node_ptr->next);

    }
#endif
}

Node* pop(Node *top)
{
    int pop_data;

    if(!StackIsEmpty(top))
    {
        Node* Node_Ptr = top;
        pop_data = Node_Ptr->data;
        top=top->next;

        printf("Stack pop [%d]\n",pop_data);
        free(Node_Ptr);
    }


    return top;
}

Node* push(Node *top, int data)
{
    Node *Node_Ptr = (Node *)malloc(sizeof(Node));

    if(Node_Ptr)
    {
        //malloc a new node, pointer top point to the new node
        Node_Ptr->data = data;
        Node_Ptr->next = top;
        top = Node_Ptr;

        printf("Stack push [%d]\n",data);
    }
    else
    {
        printf("New node malloc fail.\n");
    }

    return top;
}

void Stack_Test(Node *stack, Node *top)
{
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    top = push(top, 6);
    Stack_Print(top);

    top = pop(top);
    Stack_Print(top);
    top = pop(top);
    Stack_Print(top);

    top = push(top, 12);
    top = push(top, 13);
    Stack_Print(top);

    top = pop(top);
    Stack_Print(top);

    top = pop(top);
    top = pop(top);
    top = pop(top);
    Stack_Print(top);

    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
}

int main()
{
    Node *stack = NULL;
    Node *top = NULL;

    Stack_Test(stack, top);

    return 0;
}
