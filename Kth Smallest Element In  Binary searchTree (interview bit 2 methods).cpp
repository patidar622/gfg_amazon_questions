/*
Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
 NOTE : You may assume 1 <= k <= Total number of nodes in BST 



*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // using inoder traversal
void find_solution(TreeNode* A,int& B,int& ans)
{
    if(A==NULL)
     return;
    find_solution(A->left,B,ans);
    B--;
    if(B==0)
    {
        ans=A->val;
        return;
    }
    if(B)
    find_solution(A->right,B,ans);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    int ans=-1;
    if(A==NULL)
    return ans;


    find_solution(A,B,ans);
    return ans;
    
    
    /*
   // using priority queue
    priority_queue<int>n1;
    queue<TreeNode*>q1;
    q1.push(A);
    while(!q1.empty())
    {
        TreeNode* t1=q1.front();q1.pop();
        if(n1.size()<B)
        {
            n1.push(t1->val);
        }
        else if(n1.size()==B && n1.top()>t1->val)
        {
            n1.pop();
            n1.push(t1->val);
        }
        if(t1->left)
        q1.push(t1->left);
        if(t1->right)
        q1.push(t1->right);
    }
    return n1.top();*/
}

