#include<stdio.h>
#include<conio.h>

typedef struct Node
{
    int info;
    int *top;
    int *next;


}Node;
Node *top = NULL;

void push(int item)
{
    Node *temp;
    temp=(Node*)malloc(sizeof(Node));
    if(top == NULL)
    {
        temp->info=item;
        temp->next=NULL;
        top = temp;
    }
    else
    {
        temp->info=item;
        temp->next=top;
        top = temp;
    }
}
void pop()
{
    Node *temp;
    if(top==0)
    {
        printf("Stack contains no elements. ");
        return;
    }

    else
    {
        temp = top;
        top = top->next;
        printf("Poped item is %d.",temp->info);
        free(temp);
    }
}
void display()
{
    Node *temp;
    temp = top;
    if(top == NULL)
    {
        printf("Stack contains no elements.");
        return;
    }
    else
    {
        printf("\nElements present in the stack: \n");
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
        printf("\n Implementation of stack using linked list.\n\tMenu\n");
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.DISPLAY\n");
    printf("4.EXIT\n\n");
    printf("Enter choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("Enter the data to push onto the stack : ");
        scanf("%d",&item);
        push(item);
        break;
    case 2:
        pop();
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
