/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
struct node search(styruct node *root,struct node **par,int data)
{
    struct node *temp=NULL,loc=NULL;
    temp=root;
    if(temp == NULL){
        return NULL;
    }
    else if(temp->data == data){
                loc = temp;
                *par = NULL;
                return loc;
        }
    else{
        *par = temp;
        if(temp->data > data)
            temp=temp->left
        else
            temp= temp->right;
        while(temp!=NULL){
            *par = temp;0
            if(temp->data == data){
                loc = temp;
                return loc;
            }
            else if(temp->data > data)
                temp = temp->keft;
            else
                temp= temp->right;
        }
    }
    return NULL;
}
struct node* insert( struct node* root, int data ) {
		struct node *temp,struct node *loc,struct node *par;
        temp =(struct node*)malloc(sizeof(struct node));
        temp->data = data;
        if(root == NULL)
            root = temp;
        else{
            loc = search(root,&par,data)
                if(loc==NULL){
                    if(par->data > data){
                        par->left = temp; 
                    }
                    else
                        par->right = temp
                    }
            }
	
}
