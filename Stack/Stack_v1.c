/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define STACK_SIZE 10

int top = -1;

int StackIsFull()
{
    if(top == (STACK_SIZE-1))
        return 1;
    else
        return 0;
}

int StackIsEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void Stack_Print(int *stack)
{
    printf("Stack: ");
    
    if(top == -1)
        printf("Empty");

    for(int i = 0;i <= top;i++)
        printf("[%d] ",stack[i]);
    printf("\n");
}

int pop(int* stack)
{
    int pop_val = 0;

    if(StackIsEmpty())
    {
        printf("Stack Empty!! Pop fail.\n");
        return -1;
    }
    else
    {
        pop_val = stack[top];
        top = top -1;

        printf("Pop [%d] Sucess!\n",pop_val);
    }

    return pop_val;
}

int push(int *stack, int val)
{
    if(!StackIsFull())
    {
        top = top + 1;
        stack[top] = val;
        printf("Push [%d] Sucess!\n", val);

        return 1;
    }
    else
    {
        printf("Stack Full!!Push [%d] fail.\n",val);
        return 0;//fail
    }
}

void Stack_Test(int *Stack)
{
    int pop_val = 0;

    /*
    Test cases 
    1.Pop when Stack is empty
    2.Pop when Stack is not empty
    3.Push when Stack is Full
    4.Push when Stack is not full
    */

    printf("Stack Test Start\n\n");
    Stack_Print(Stack);
    pop_val = pop(Stack);
    printf("Pop [%d]\n",pop_val);
    pop_val = pop(Stack);
    printf("Pop [%d]\n",pop_val);
    Stack_Print(Stack);
    push(Stack, 10);
    push(Stack, 5);
    push(Stack, 3);
    push(Stack, 7);
    Stack_Print(Stack);
    pop_val = pop(Stack);
    printf("Pop [%d]\n",pop_val);
    Stack_Print(Stack);
    push(Stack, 11);
    push(Stack, 12);
    push(Stack, 13);
    Stack_Print(Stack);
    pop_val = pop(Stack);
    printf("Pop [%d]\n",pop_val);
    pop_val = pop(Stack);
    printf("Pop [%d]\n",pop_val);
    Stack_Print(Stack);
    push(Stack, 24);
    push(Stack, 35);
    push(Stack, 31);
    Stack_Print(Stack);
    pop_val = pop(Stack);
    printf("Pop [%d]\n",pop_val);
    Stack_Print(Stack);
    push(Stack, 32);
    push(Stack, 33);
    push(Stack, 34);
    push(Stack, 35);
    push(Stack, 36);
    push(Stack, 37);
    push(Stack, 38);

    Stack_Print(Stack);
    printf("\nStack Test Over\n");
}
int main()
{
    int Stack[STACK_SIZE];
    int pop_val = 0;

    for(int i = 0;i<STACK_SIZE;i++)
        Stack[i] = 0;

    Stack_Test(Stack);

    return 0;
}
