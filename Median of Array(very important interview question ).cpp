/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
 NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element.
For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 

*/
int find_solution(const vector<int>& A,int i,const vector<int>& B,int j,int k)
{
    if(i>A.size()-1)return B[j+k-1];
    if(j>B.size()-1)return A[i+k-1];
    
    if(k==1)return min(A[i],B[j]);
    
    int a_mid=INT_MAX,b_mid=INT_MAX;
    if(i+k/2-1<A.size())
    a_mid=A[i+k/2-1];
    if(j+k/2-1<B.size())
    b_mid=B[j+k/2-1];
    
    if(a_mid<b_mid)
    return find_solution(A,i+k/2,B,j,k-k/2);
    else
    return find_solution(A,i,B,j+k/2,k-k/2);
}
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int m=A.size(),n=B.size();
    if(m==0)
    {
        if(n%2==0)
        return (B[n/2]+B[n/2-1])/2.0;
        else
        return B[n/2];
    }
    else if(n==0)
    {
         if(m%2==0)
        return (A[m/2]+A[m/2-1])/2.0;
        else
        return A[m/2];
    }
    int t=(m+n);
    int l=(t+1)/2;
    int r=(t+2)/2;
    return (find_solution(A,0,B,0,l)+find_solution(A,0,B,0,r))/2.0;
}

