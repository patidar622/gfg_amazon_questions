/*
Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.

1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9
N*M is odd



*/
int Solution::findMedian(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
    int d=(n*m+1)/2;
    int min1=INT_MAX,max1=INT_MIN;
    for(int i=0;i<n;i++)
    {
        min1=min(min1,A[i][0]);
        max1=max(max1,A[i][m-1]);
    }
    while(min1<max1)//we are breaking the loop when min1==max1 i.e, when we find the median 
    {
        int mid=min1+(max1-min1)/2;
        int p=0;
        for(int i=0;i<n;i++)
        {
            p+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        }
        if(p<d)
        min1=mid+1;
        else
        max1=mid;
        
    }
    return min1;
}

