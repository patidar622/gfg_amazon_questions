/*
Problem Description

Given a undirected tree with N nodes labeled from 1 to N.

Each node has a certain weight assigned to it given by an integer array A of size N.

You need to delete an edge in such a way that Product between sum of weight of nodes in one subtree with sum of weight of nodes in other subtree is maximized.

Return this maximum possible product modulo 109 + 7.

NOTE:

The tree is rooted at node labeled with 1.


Problem Constraints
2 <= N <= 105

1 <= A[i] <= 103



Input Format
First argument is an integer array A of size N denoting the weight of each node.

Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.



Output Format
Return a single integer denoting the maximum product prossible of sum of weights of nodes in the two subtrees formed by deleting an edge with modulo 109 + 7.



Example Input
Input 1:

 A = [10, 5, 12, 6]
 B = [

        [1, 2]
        [1, 4]
        [4, 3]
     ]
Input 2:

 A = [11, 12]
 B = [

        [1, 2]
     ]


Example Output
Output 1:

 270
Output 2:

 132


Example Explanation
Explanation 1:

 Removing edge (1, 4) created two subtrees.
 Subtree-1 contains nodes (1, 2) and Subtree-2 contains nodes (3, 4)
 So product will be = (A[1] + A[2]) * (A[3] + A[4]) = 15 * 18 = 270
Explanation 2:

 Removing edge (1, 2) created two subtrees.
 Subtree-1 contains node (1) and Subtree-2 contains node (3)
 So product will be = (A[1]) * (A[2]) = 11 * 12 = 132

*/
long long int m=1000000007;
void find_solution(vector<int>&A,int start,int par,map<int,vector<int>>& m1,long long int& sum,long long int& ans)
{
   int l1=A[start-1];
    for(auto& i:m1[start])
    {
        if(i!=par){
        find_solution(A,i,start,m1,sum,ans);
        l1+=A[i-1];
        }
    }
    A[start-1]=l1;
    if(start==1) return;
    
    ans=max(ans,(l1*(sum-l1))%m)%m;
}
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    long long int ans=0;
    long long int sum=0;
for(auto i:A)
sum+=i;
map<int,vector<int>>m1;
    for(int i=0;i<B.size();i++)
    {
        m1[B[i][0]].push_back(B[i][1]);
        m1[B[i][1]].push_back(B[i][0]);
    }
    find_solution(A,1,0,m1,sum,ans);
    return ans%m;
}

