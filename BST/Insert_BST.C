#include<stdio.h>
#include<conio.h>
typedef struct nodetype
{
	int color;
	struct nodetype *left;
	struct nodetype *right;
	struct nodetype *parent;
	int key;
}node;
void insert_tree(node **root);
void inorder(node *root);
void main()
{
	node *root=NULL;
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	insert_tree(&root);
	inorder(root);
	getch();
}
void insert_tree(node **root)
{
	node *ptr,*parloc,*temp;
	int loc;
	ptr=(node*)malloc(sizeof(node));
	scanf("%d",&ptr->key);
	ptr->left = NULL;
	ptr->right = NULL;
	if(*root == NULL)
	{
		(*root)=ptr;
		(*root)->parent=NULL;
	}
	else
	{
		temp = (*root);
		loc = search(temp,ptr->key,&parloc);
		if(loc != 0)
			printf("Value Already Exist");
		else
		{
			if(ptr->key > parloc->key)
			{
				parloc->right = ptr;
				ptr->parent = parloc;
			}
			else
			{
				parloc->left = ptr;
				ptr->parent = parloc;
			}

		}
	}
}
int search(node *root,int item,node **parloc)
{
	while(root != NULL)
	{
		if(root->key == item)
		{
			*parloc = NULL;
			return -1;
		}
		else
		{
			if( item > root->key)
			{
				*parloc=root;
				root=root->right;
			}
			else
			{
				*parloc = root;
				root = root->left;
			}

		}
	}
	return 0;
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->key);
		inorder(root->right);
	}
}
