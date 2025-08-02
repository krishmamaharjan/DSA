#include<stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
}Node;
//fn dec
Node* get_newnode();
void insert_node();
void insert_at_beg(int);
void insert_at_end(int);
void delete_node();
void del_from_beg();
void del_from_end();
void display();
Node *head = NULL;
int main()
{
    int choice,i;
    int loop_is_on = 1;
    while(loop_is_on){
    printf("---------------------------");
    printf("\nChoose: \n");
    printf("1:Insert a new node:\n2:Delete a node\n3:Display all nodes\n4:End\n-->");
    scanf("%d",&choice);
    switch(choice)
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
        loop_is_on = 0;
        break;
        default:
        printf("not a valid choice\n");
    }
}
return 0;
}
//fn def
Node* get_newnode(){
Node * newnode = (Node *) malloc(sizeof(Node));
newnode->next = NULL;
return newnode;
}
// insertion switch case
void insert_node()
{
    int choice,data_to_add;
    printf("----INSERTION-----\n");
    printf("Enter data to insert: ");
    scanf("%d",&data_to_add);
    if (head == NULL)
    {
        head = get_newnode();
        head->data = data_to_add;
        printf("---%d added in linked list at first node ----\n ",data_to_add);
        return;
    }
    printf("Choose: \n");
    printf("1:At beinning\n2:At End\n3:Go Back\n-->");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        insert_at_beg(data_to_add);
        break;
        case 2:
        insert_at_end(data_to_add);
        break;
        case 3:
        break;
        default:
        printf("invalid choice\n");
    }
}
//insertion diff modes
void insert_at_beg(int new_item)
{
    Node *newnode = get_newnode();
    newnode->data = new_item;
    newnode->next = head;
    head = newnode;
    printf("---%d inserted at beginning---\n",new_item);
}
void insert_at_end(int new_item)
{
    Node *newnode = get_newnode();
    newnode->data = new_item;
    Node *temp = head;
    while(temp->next!=NULL){
    temp=temp->next;
}
    temp->next = newnode;
    printf("---%d inserted at end---\n",new_item);
}
// deletion options
void delete_node()
{
    int choice,data_taken_out;
    if(head == NULL)
    {
        printf("--there is no node to delete\n--");
        return;
    }
    else if(head->next == NULL)
    {
            data_taken_out = head->data;
            head =NULL;
            printf("--Only one node detected---\n ");
            printf("----%d was taken out----\n",data_taken_out);
            return;
    }
    printf("---DELETION---\n");
    printf("CHOOSE\n");
    printf("1:From Beginning\n2:From End\n3:Go back\n-->");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        del_from_beg();
        break;
        case 2:
        del_from_end();
        break;
        case 3:
        break;
        default:
        printf("Invalid Choice\n");
    }
}
//deletion modes:
void del_from_beg()
{
    Node *temp = head;
    printf("--%d taken out from beginning--\n",head->data);
    head = head->next;
    free(temp);
}
void del_from_end()
{
    Node *temp = head;
    while(temp->next->next != NULL){
    temp = temp->next;
}
    printf("--%d taken out from end--\n",temp->next->data);
    free(temp->next);
    temp->next = NULL;
}
void display()
{
    int i;
    Node *temp = head;
    if (head == NULL){
    printf("Nodes Empty\n");
    return;
}
printf("--Data in All Nodes ---\n");
while(temp!= NULL)
{
    printf("%d\n",temp->data);
    temp = temp->next;
}
}
