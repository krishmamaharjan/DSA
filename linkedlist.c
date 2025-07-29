#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void insert_node();
void ins_beg();
void ins_end();
void ins_specpos();
void delete_node();
void del_beg();
void del_end();
void del_specpos();

typedef struct Node
    {
        int info;
        struct Node *next;
        struct Node *head;
    }Node;

Node *head = NULL;

Node* create()
    {
         Node *temp;
         temp=(Node*)malloc(sizeof(Node));

         //temp->info=a;
         temp->next=NULL;
         return temp;
}

void display()
{
    int i;
    Node *temp;
    temp = head ;
    if(head == NULL)
    {
        printf("Node is empty\n");
        return;
    }
    printf("\tData in all nodes\n");
    while(temp!=NULL)
    {
      printf("%d\n",temp->info);
      temp = temp->next;
    }
}


int main()
    {
    int p,q;
    while(1)
    {
        printf("\tMENU\n");
        printf("1.INSERT\n");
        printf("2.DELETE\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&p);
        switch(p)
        {
            case 1:
                insert_node();
                break;
            case 2:
                delete_node();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid");


    }
    }


return 0;

}
    //insertion

void insert_node()
{
    int q,add_data;
            printf("Enter the data to insert at node : ");
            scanf("%d",&add_data);
            if(head==NULL)
            {
                head=create();
                head->info = add_data;
                printf("%d is added to the node.",add_data);
            }
            printf("\n\n1Insert at beginning\n");
            printf("2.Insert at the end\n");
            printf("3.Insert at specfic position\n");
            printf("Enter your choice : ");
            scanf("%d",&q);
            switch(q)
            {
                case(1):
                    ins_beg(add_data);
                    break;
                case(2):
                    ins_end(add_data);
                    break;
                case(3):
                    ins_specpos(add_data);
                    break;
                default:
                printf("Invalid option.\n");
                break;
            }

}
void ins_beg(int add_data)
{
    Node *Newnode;
    Newnode=create();
    Newnode->info = add_data;
    Newnode->next=head;
    head=Newnode;
    printf("Newnode inserted at the beginning : %d\n",add_data);

}

void ins_end(int add_data)
{
    Node *Newnode;
    Node *temp;
    Newnode=create();
    Newnode->info = add_data;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=Newnode;
    printf("Newnode inserted at the end : %d\n",add_data);


    }

void ins_specpos(int add_data)
    {

        int i=0,pos;
        Node *Newnode;
        Node *temp;
        Newnode=create();
        printf("Enter a position of node at which you want to insert data. : ");
        scanf("%d",&pos);
        Newnode->info = add_data;
        temp=head;
        //while(i<pos-1)
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;

        }
        Newnode->next = temp->next;
        temp->next=Newnode;
        printf("Newnode inserted at the specific position : %d\n",add_data);

}

 //deletion

void delete_node()
{

    int d,out_data;
    if(head==NULL)
    {
        printf("Empty node\n");
        return;
    }
    printf("\n\n1Delete at beginning\n");
    printf("2.Delete at the end\n");
    printf("3.Delete at specfic position\n");
    scanf("%d",&d);
    switch(d)
    {
        case(1):
            del_beg(out_data);
            break;
        case(2):
            del_end(out_data);
            break;
        case(3):
            del_specpos(out_data);
            break;
        default:
        printf("Invalid option.\n");
        break;
    }
}
void del_beg(int out_data)
{
    Node *temp;
    temp = head;
    printf("%d is deleted from beginning.\n",head->info);
    head = head->next;
    free(temp);
}
void del_end(int out_data)
{
    Node *temp;
    temp = head;
   /* if(head->next=NULL)
    {
        temp = head;
        printf("%d is deleted from end.\n",head->info);
        head == NULL;
        free(temp);
    }
    else
    {
        temp = head;*/
        while(temp->next->next != NULL)
        {
            temp =temp->next;
        }
        printf("%d is deleted from end.\n",temp->next->info);
        free(temp->next);
        temp->next = NULL;

}
void del_specpos(int out_data)
{
    Node *temp;
    Node *p;
    temp = head;
    int pos;
    printf("Enter a position of node at which you want to delete node : ");
    scanf("%d",&pos);
    for(int i=1;i<pos-1;i++)
    {
        temp = temp->next;

    }
    p=temp->next;
    temp->next=temp->next->next;
    free(p);
    printf("%d is deleted from a specific position.",temp->next->info);
}
