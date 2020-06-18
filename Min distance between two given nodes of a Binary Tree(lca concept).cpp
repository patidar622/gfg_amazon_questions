Node* find_solution(Node* root,int a,int b)
{
    if(root==NULL)
    return NULL;
    if((root->data==a)||(root->data==b))
    return root;
    Node *l1=find_solution(root->left,a,b);
    Node *r1=find_solution(root->right,a,b);
    if(l1 && r1)
    return root;
    return (l1!=NULL)? l1:r1;
}
int find_distance(Node* root,int i)
{
    if(root==NULL)
    return INT_MAX-1100;
    if(root->data==i)
    return 0;
    int i1=find_distance(root->left,i);
    int i2=find_distance(root->right,i);
    return 1+min(i1,i2);
}
int findDist(Node* root, int a, int b) {
    
          Node* n1=find_solution(root,a,b); 
          int i1=find_distance(n1,a);
          int i2=find_distance(n1,b);
          return (i1+i2);
}
