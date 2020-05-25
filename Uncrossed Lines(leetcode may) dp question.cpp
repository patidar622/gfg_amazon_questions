/*
We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.
Example 1:


Input: A = [1,4,2], B = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
*/
class Solution {
public:
    vector<vector<int>>dp;
    int find_solution(vector<int>& A,vector<int>& B,int i,int j)
    {
        if(i==A.size()|| j==B.size())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int max1=0;
        for(int i1=i;i1<A.size();i1++)
        {
            for(int j1=j;j1<B.size();j1++)
            {
                if(A[i1]==B[j1])
                {
                  int ans=max(1+find_solution(A,B,i1+1,j1+1),find_solution(A,B,i1,j1+1));
                    max1=max(ans,max1);
                }
            }
        }
        return   dp[i][j]=max1;
        
    }
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        
        int i=0,j=0;
        dp.resize(A.size()+1,vector<int>(B.size()+1,-1));
        return find_solution (A,B,i,j);
    }
};
