#include<stdio.h>
#include<conio.h>
#define red 1
#define black 0

typedef struct nodetype

{

	int color;

	struct nodetype *left;

	struct nodetype *right;

	struct nodetype *parent;

	int key;
}node;

void left_rotate(node **root,node *x);

void RBinsert(node **root);

node* insert_tree(node **root);

void inorder(node *root);

void main()

{

	node *root=NULL;

	int n,i;

	//scanf("%d",&n);

	//for(i=0;i<n;i++)

	RBinsert(&root);
	//insert_tree(&root);

	//inorder(root);

	getch();

}

node* insert_tree(node **root)

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

	return ptr;

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



		printf("x = %d parent = %d color = %d",root->key,root->parent,root->color);

		inorder(root->left);
		inorder(root->right);

	}

}

void RBinsert(node **root)
{
	node *x,*y;
	x = insert_tree(root);
	x->color = red;
	while(x != (*root) && (x->parent)->color == red)
	{
		if(x->parent == (x->parent->parent)->right)
		{
			y = x->parent->parent->right;
			if(y->color == red)
			{
				x->parent->color = black;
				y->color = black;
				x->parent->parent->color = red;
				x = x->parent->parent;
			}
			else if(x == x->parent->right)
			{
				x = x->parent;
				left_rotate(root,x);
			}
			x->parent->color=black;
			x->parent->parent->color=red;
			right_rotate(root,x->parent->parent);

		}
		else
		{
			y = x->parent->parent->left;
			if(y->color == red)
			{
				x->parent->color = black;
				y->color = black;
				x->parent->parent->color = red;
				x = x->parent->parent;
			}
			else if(x == x->parent->left)
			{
				x = x->parent;
				right_rotate(root,x);
			}
			x->parent->color=black;
			x->parent->parent->color=red;
			left_rotate(root,x->parent->parent);
		}
	}

}
void left_rotate(node **root,node *x)
{
	node *y;
	y=x->right;
	x->right = y->left;
	if(y->left !=NULL)
	{
		y->left->parent = x;

	}
	y->parent = x->parent;
	if(x->parent == NULL)
	{
		(*root) = y;
	}
	else if(x == x->parent->left)
	{
		x->parent->left = y;

	}
	else
	{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;

}
