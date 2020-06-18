Node* find_solution(Node* n1)
{
    while(n1->left!=NULL)
    {
        n1=n1->left;
    }
    return n1;
}
Node * inOrderSuccessor(Node *root, Node *x)
{
    Node* ans=NULL;
         if(x->right!=NULL)
         return find_solution(x->right);
         else
         {
             while(root!=NULL)
             {
                 if(root->data>x->data)
                 {ans=root;
                 root=root->left;}
                 else if(root->data<x->data)
                 root=root->right;
                 else
                 return ans;
             }
         }
         
}
