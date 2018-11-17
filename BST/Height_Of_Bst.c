int getHeight(struct node* root) {
    // Write your code here
    int lHeight,rHeight;
    if(root == NULL)
        return -1;
    else{
        lHeight = getHeight(root->left);
        rHeight = getHeight(root->right);
        return( lHeight > rHeight ? 1+lHeight : 1+rHeight );
    }
}
