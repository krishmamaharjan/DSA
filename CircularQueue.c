#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define maxsize 10
int cqueue[maxsize];
int rear = -1,front = -1;
int enqueue();
int dequeue();
void peek();
void display();
int isfull()
{
    if((rear+1)%maxsize==front)
    {
        printf("circular queue is full.");
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if(front==-1)
    {
        printf("circular queue is empty.");
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
        printf("\nMenu for circular queue operation.\n");
        printf("\n 1.Enqueue");
        printf("\n 2.Dequeue");
        printf("\n 3.Peek");
        printf("\n 4.Display");
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
                peek();
                break;
            case 4:
                display();
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
        if(front == -1 && rear ==-1)
        rear = rear+1;
        front = 0;
        printf("Enter the elements in circular queue : \n");
        for(int i=0;i<maxsize;i++)
        {

            scanf("%d",&item);
            rear=rear+1;
            cqueue[rear]=item;
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
        front = (front+1)%maxsize;
        int item;
        item = cqueue[front];
        printf("Element dequeued from circular queue is %d \n\n",item);
        front = front + 1;
    }
}
void display()
{
    if(front==-1)
    {
        printf("circular queue is empty");
    }
    else
    {
        //for(int i=front;i<rear;i=(front+1)%maxsize)
        /*for(int i=front;i<rear;i++)
        {
            printf("%d\t",cqueue[i]);
        }
        printf("\n");*/
        int i = front;
         printf("\nCircular Queue Elements are : \n");
      if(front <= rear){
	 while(i <= rear)
	    printf("%d\t",cqueue[i++]);
      }
      else{
	 while(i <= maxsize - 1)
	    printf("%d\t", cqueue[i++]);
	 i = 0;
	 while(i <= rear)
	    printf("%d\t",cqueue[i++]);
      }
    }
}
void peek()
{
    printf("Element at front of the queue is %d \n",cqueue[front]);
}
