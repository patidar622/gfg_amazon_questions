/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).





*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<TreeNode*>q1;
        q1.push_back(root);
        int ans=0;
        while(!q1.empty())
        {
            while(!q1.empty() && q1.front()==NULL){q1.pop_front();}
            while(!q1.empty() && q1.back()==NULL){q1.pop_back();}
            int t=q1.size();
            ans=max(ans,t);
            for(int i=0;i<t;i++)
            {
                TreeNode* temp=q1.front();q1.pop_front();
                
                if(temp!=NULL)
                {
                        q1.push_back(temp->left);
                        q1.push_back(temp->right);
                }
                else
                {
                    q1.push_back(NULL);
                   q1.push_back(NULL);
                }
            }
        }
        return ans;
    }
};
