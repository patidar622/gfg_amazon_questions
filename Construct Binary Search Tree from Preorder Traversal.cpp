class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root=new TreeNode(pre[0]);
        stack<TreeNode*>s;
        s.push(root);
        for(int i=1;i<pre.size();i++)
        {
            TreeNode* temp=NULL;
            while(!s.empty() && s.top()->val<pre[i])
            {
                temp=s.top();
                s.pop();
            }
            if(temp!=NULL)
            {
                TreeNode* temp1=new TreeNode(pre[i]);
                temp->right=temp1;
                s.push(temp1);
            }
            else
            {
                 TreeNode* temp1=new TreeNode(pre[i]);
                s.top()->left=temp1;
                 s.push(temp1);
            }
        }
        return root;
    }
};
