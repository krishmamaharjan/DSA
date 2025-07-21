#include<stdio.h>
#include<conio.h>

typedef struct Node
{
    int info;
    int *rear;
    int *front;
    int *next;


}Node;
Node *front = NULL;
Node *rear = NULL;


void insert(int item)
{
    Node *temp;
    temp=(Node*)malloc(sizeof(Node));
    if(rear == NULL)
    {
        temp->info=item;
        temp->next=NULL;
        //rear->next=temp;
        //rear = temp;
        rear = front = temp;
    }
    else
    {
        temp->info=item;
        temp->next=NULL;
        rear->next=temp;
        rear = temp;
    }
}
void deleteq()
{
    Node *temp;
    if(front == NULL)
    {
        printf("Queue contains no elements. ");
        return;
    }

    else if(front->next == NULL)
    {
        temp = front;
        rear = front = NULL;
        printf("Dequeued item is %d.",temp->info);
        free(temp);
    }
    else
    {
        temp = front;
        front = front->next;
        printf("Dequeued item is %d.",temp->info);
        free(temp);
    }
}
void display()
{
    Node *temp;
    temp = front;
    if(front == NULL)
    {
        printf("Queue contains no elements.");
        return;
    }
    else
    {
        printf("\nElements present in the Queue. \n");
        while(temp != NULL)
        {

            printf("%d\n",temp->info);
            temp = temp->next;

        }



    }
}
int main()
{
    int ch,item;
    while(1)
    {
        printf("\n Implementation of Queue using linked list.\n\tMenu\n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.DISPLAY\n");
    printf("4.EXIT\n\n");
    printf("Enter choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("Enter the data in queue : ");
        scanf("%d",&item);
        insert(item);
        break;
    case 2:
        deleteq();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(1);
    default:
        printf("invalid");
    }
    }

}

