/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.



*/
int Solution::firstMissingPositive(vector<int> &A) {
    
    int c=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==1)
        c=1;
        if(A[i]<=0 || A[i]>A.size())
        A[i]=1;
    }
    if(c==0)
    return 1;
    for(int i=0;i<A.size();i++)
    {
        A[abs(A[i])-1]=-1*abs(A[abs(A[i])-1]);
    }
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>0)
        return i+1;
    }
    return A.size()+1;
}


