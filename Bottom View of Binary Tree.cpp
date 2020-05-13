void bottomView(Node *root)
{
   map<int,int>m1;
   m1[0]=root->data;
   queue<pair<int,Node* >>q1;
    q1.push({0,root});
   while(!q1.empty())
   {
       pair<int,Node*>p1=q1.front();
       q1.pop();
       if((p1.second)->left)
       {
          m1[p1.first-1]=((p1.second)->left)->data;
           q1.push({p1.first-1,(p1.second)->left});
       }
       if((p1.second)->right)
       {
          m1[p1.first+1]=((p1.second)->right)->data;
           q1.push({p1.first+1,(p1.second)->right});
       }
   }
   for(auto i:m1)
   {
       cout<<i.second<<" ";
   }
   m1.clear();
}

