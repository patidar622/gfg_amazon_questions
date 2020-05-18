void find_solution(Node* root,int k,priority_queue<int>& q1)
{
    if(root==NULL)
    return;
    if(q1.size()>=k && root->data<q1.top())
    {
        q1.pop();
        q1.push(root->data);
    }
    else if(q1.size()<k)
    {
        q1.push(root->data);
    }
    find_solution(root->left,k,q1);
    find_solution(root->right,k,q1);
}
int KthSmallestElement(Node *root, int k)
{
    priority_queue<int>q1;
    find_solution(root,k,q1);
    if(q1.size()==k)
       return q1.top();
   else
   return -1;
}
