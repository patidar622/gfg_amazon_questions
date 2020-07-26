/*

Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements inside the sub matrix is equal to 0. (note: elements might be negative).

Example:

Input

-8 5  7
3  7 -8
5 -8  9
Output
2

Explanation
-8 5 7
3 7 -8
5 -8 9

-8 5 7
3 7 -8
5 -8 9

*/
//these algo covers all the sub matrix of a matrix 
int find_zeros(vector<int>& v1)
{
    unordered_map<int,int>m1;
    int sum=0,count=0;
    for(int i=0;i<v1.size();i++)
    {
        sum+=v1[i];
        if(sum==0)
        count++;
        if(m1.find(sum)!=m1.end())
        {
            count+=m1[sum];
        }
        m1[sum]++;
    }
    return count;
}
int Solution::solve(vector<vector<int> > &A) {
    
    int n=A.size(),m=A[0].size();
    if(n==0 || m==0)
    return 0;
    int ans=0;
    for(int i=0;i<m;i++)
    {
        vector<int>v1(n,0);
        for(int j=i;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                v1[k]=v1[k]+A[k][j];
            }
            ans+=find_zeros(v1);
        }
    }
    return ans;
}

