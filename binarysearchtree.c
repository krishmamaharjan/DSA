#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct BST
{
	int info;
	struct BST *left;
	struct BST *right;
};
typedef struct BST ST;
struct BST *root=NULL;
void menu();

ST* create(int a)
{
	ST *temp;
	temp=(ST*)malloc(sizeof(ST));
	temp->info=a;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

ST* minValueNode(ST* node)
 {
    ST* current = node;
    while (current->left!= NULL)
	{
        current = current->left;
    }
    return current;
}

ST* deletion(ST* node, int data)
{
    if (node == NULL)
        return node;
    if (data < node->info)
        node->left = deletion(node->left, data);
	else if (data > node->info)
        node->right = deletion(node->right, data);
	else
	{
        if (node->left == NULL)
		{
            ST* temp = node->right;
            free(node);
            return temp;
        }
		else if (node->right == NULL)
		{
            ST* temp = node->left;
            free(node);
			return temp;
        }

        ST* temp = minValueNode(node->right);
        node->info = temp->info;
        node->right = deletion(node->right, temp->info);
    }
    return node;
}

ST* insertion(ST *tree, int key)
{
	if(tree==NULL)
	{
		return(create(key));
	}
	else if(tree->info>key)
		tree->left=insertion(tree->left,key);
	else
		tree->right=insertion(tree->right,key);
}

void display_preorder(ST *tree)
{
    if(tree)
    {
        printf("%d \n", tree->info);
        display_preorder(tree->left);
        display_preorder(tree->right);
    }
}

int search(int val)
{
	ST *temp;
	int i=0,tem;
	temp=root;
	while(temp!=NULL)
	{
		tem=temp->info;
		if(tem==val)
		{
			i=1;
			break;
		}
		else if(tem>val)
			temp=temp->left;
		else if(tem<val)
			temp=temp->right;
	}
	return i;
}

int main()
{
	g:
	menu();
	goto g;
}

void menu()
{
	int a,b,key,i;
	k:
		system("cls");
		printf("\tMENU\n");
		printf("1. INSERTION\n");
		printf("2. DELETE\n");
		printf("3. DISPLAY\n");
		printf("4. SEARCH\n");
		printf("Exit for other.\n");
		printf("\nEnter the option:");
		scanf("%d",&a);
		switch(a)
		{
			case(1):
				if(root==NULL)
				{
					printf("Enter the key you want to insert:");
					scanf("%d",&key);
					root=(create(key));
					printf("Root Value Inserted.\n");
					system("pause>nul");
				}
				else
				{
					printf("Enter the key you want to insert:");
					scanf("%d",&key);
					insertion(root, key);
					printf("%d inserted to the tree.\n",key);
					system("pause>nul");
				}
				break;
			case(2):
				if(root==NULL)
				{
					printf("Empty BST.\n");
					system("pause>nul");
				}
				else
				{
					printf("Enter the key you want to delete:");
					scanf("%d",&key);
					i=search(key);
					if(i==0)
						printf("Value not present in the bst");
					else
						deletion(root, key);
					system("pause>nul");
				}
				break;
			case(3):
				if(root==NULL)
				{
					printf("Empty BST.\n");
					system("pause>nul");
				}
				else
				{
					display_preorder(root);
					system("pause>nul");
				}
				break;
			case(4):
				if(root==NULL)
				{
					printf("Empty BST.\n");
					system("pause>nul");
				}
				else
				{
					printf("Enter the key you want to search:");
					scanf("%d",&key);
					i=search(key);
					if(i==0)
						printf("Value not present in the bst");
					else
						printf("Value present in the bst");
					system("pause>nul");
				}
				break;
			default:
				exit(0);
				break;
		}
}
