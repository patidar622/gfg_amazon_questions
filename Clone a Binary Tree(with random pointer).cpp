Node* find_solution(Node* tree,map<Node*,Node*>&m1)
{
  if(tree==NULL)
  return tree;
  
      Node* n1=new Node(tree->data);
      
      if(tree->random!=NULL)
      m1[n1]=tree->random;
      n1->left=find_solution(tree->left,m1);
      n1->right=find_solution(tree->right,m1);
      return n1;
  
}
Node* cloneTree(Node* tree)
{
   
   map<Node*,Node*>m1;
   Node* root=find_solution(tree,m1);
   for(auto i:m1)
   {
       i.first->random=i.second;
   }
   return root;
}

