// inorder non recursive
vector<int> Solution::inorderTraversal(TreeNode* root) {
   vector<int>ans;
   stack<TreeNode*>s1;
   while(1)
   {
       while(root!=NULL)
       {
           s1.push(root);
           root=root->left;
       }
       if(s1.empty())
       break;
       
       root=s1.top();
       s1.pop();
       ans.push_back(root->val);
       root=root->right;
   }
   return ans;
}
//postorder non recursive
vector<int> Solution::postorderTraversal(TreeNode* root) {
   stack<TreeNode*>s1;
   vector<int>ans;
   TreeNode* prev=NULL;
   do{
       while(root!=NULL)
       {
          s1.push(root);
          root=root->left;
       }
       while(root==NULL && !s1.empty())
       {
           root=s1.top();
           if(root->right==NULL || root->right==prev)
           {
               ans.push_back(root->val);
               prev=root;
               s1.pop();
               root=NULL;
           }
           else
           root=root->right;
       }
    }while(!s1.empty());
   return ans;
}
// preorder non recursive
vector<int> Solution::preorderTraversal(TreeNode* root) {
    vector<int>ans;
    stack<TreeNode*>s1;
    while(1)
    {
        while(root!=NULL)
        {
            ans.push_back(root->val);
            s1.push(root);
            root=root->left;
        }
        if(s1.empty())
        break;
        
        root=s1.top();
        s1.pop();
        root=root->right;
    }
    return ans;
}

