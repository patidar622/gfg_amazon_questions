/*
Given a matrix of integers A of size N x M and an integer B.

Write an efficient algorithm that searches for integar B in matrix A.

This matrix A has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Return 1 if B is present in A, else return 0.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.

*/
int find_solution(vector<int> v,int B)
{
    int i=0,j=v.size()-1;
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(v[mid]==B)
        return 1;
        if(v[mid]>B)
        j=mid-1;
        else
        i=mid+1;
    }
    return 0;
}
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int i=0,j=A[0].size()-1;
    while(i<A.size() && j>=0)
    {
        if(A[i][j]==B)
        return 1;
        
        if(A[i][j]>B)
        j--;
        else
        i++;
    }
    return 0;
    /*
    for(int i=0;i<A.size();i++)
    {
        if(find_solution(A[i],B))
        return 1;
    }
    return 0;*/
}

