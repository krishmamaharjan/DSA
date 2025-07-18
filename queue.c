#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define maxsize 10
int queue[maxsize];
int rear = -1,front = -1;
int enqueue();
int dequeue();
void display();
void peek();
int isfull()
{
    if(rear==maxsize-1)
    {
        printf("Queue is full.");
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if(rear<front || front==rear)
    {
        printf("Queue is empty.");
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("\nMenu for queue operation.\n");
        printf("\n 1.Enqueue");
        printf("\n 2.Dequeue");
        printf("\n 3.Display");
        printf("\n 4.Peek");
        printf("\n 5.Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
            default:
                printf("invalid choice");
                break;
        }

    }
    return 0;
}

int enqueue()
{
    int item;
    if(isfull())
    {
        return 1;
    }
    else
    {
        if(front == -1)
        front = 0;
        printf("Enter the elements in queue : \n");
        for(int i=0;i<maxsize;i++)
        {

            scanf("%d",&item);
            rear=rear+1;
            queue[rear]=item;
        }

    }
}
int dequeue()
{

    if(isempty())
    {
        return 1;
    }
    else
    {
        printf("Element dequeued from queue is %d \n\n",queue[front]);
        front = front + 1;
    }
}
void display()
{
    if(front==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }
}
void peek()
{
    printf("Element at front of the queue is %d \n",queue[front]);
}
