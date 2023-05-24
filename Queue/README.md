# C code implement discription
### Queue_v1
* Queue with fixed array size
* Define initinal rear, front, size to -1
* Rear / size will increase when enqueue
* Front / size will decrease when dequeue
* The major function implementation of enqueue and dequeue as below
```
int enqueue(int* Queue, int data)
{
    DEBUG
    if(size < MAXSIZE) //make sure queue not full
    {
        printf(RED_BOLD"Queue enqueue [%d]\n"RESET,data);
        if(size < 0) //Initial case
        {
            Queue[0] = data;
            front = rear = 0;
            size = 1;
        }
        else if(rear == MAXSIZE -1) // when rear is last element, add new element to index 0
        {
            Queue[0] = data;
            rear = 0;
            size++;
        }
        else
        {
            //Normal case
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
```
```
int dequeue(int* Queue)
{
    DEBUG
    if(size < 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        //increase front and decrease size by 1
        printf(RED_BOLD"Queue dequeue [%d]\n"RESET,Queue[front]);
        
        size--;
        front++;
    }
}
```
C file link: [Queue_v1.c](Queue_v1.c)
