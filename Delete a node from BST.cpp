int find_min(Node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}
Node* find_solution(Node* root,int x)
{
    if(root==NULL)
    return NULL;
    
    if(root->data==x)
    {
        if(root->left==NULL && root->right==NULL)
          return NULL;
    if(root->left==NULL && root->right!=NULL)
    return root->right;
    if(root->left!=NULL && root->right==NULL)
    return root->left;
    if(root->left!=NULL && root->right!=NULL)
    {
        int m1=find_min(root->right);
        root->data=m1;
        root->right=find_solution(root->right,m1);
        return root;
    }
    }
    
    if(root->data>x)
     root->left=find_solution(root->left,x);
     else
     root->right=find_solution(root->right,x);
     return root;
}
Node *deleteNode(Node *root,  int x)
{
    find_solution(root,x);
}
