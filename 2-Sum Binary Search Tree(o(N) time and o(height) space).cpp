/*
Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.


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
 // this question can be solved with other methods but this will follow constraints
int Solution::t2Sum(TreeNode* A, int B) {
    stack<TreeNode*>t1,t2;
    TreeNode* c=A;
    while(c)
    {
        t1.push(c);
        c=c->left;
    }
    c=A;
    while(c)
    {
        t2.push(c);
        c=c->right;
    }
    while(t1.top()!=t2.top())
    {
        int n=t1.top()->val+t2.top()->val;
        if(n==B)
        return 1;
        if(n<B)
        {
            c=t1.top();
            t1.pop();
            c=c->right;
            while(c){
                t1.push(c);c=c->left;
            }
        }
        else
        {
            c=t2.top();
            t2.pop();
            c=c->left;
            while(c)
            {
                t2.push(c);c=c->right;
            }
        }
    }
    return 0;
}

