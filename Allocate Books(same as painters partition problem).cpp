/*
Given an array of integers A of size N and an integer B.

College library has N bags,the ith book has A[i] number of pages.

You have to allocate books to B number of students so that maximum number of pages alloted to a student is minimum.

A book will be allocated to exactly one student.
Each student has to be allocated at least one book.
Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
Calculate and return that minimum possible number.

NOTE: Return -1 if a valid assignment is not possible.

Input 1:
    A = [12, 34, 67, 90]
    B = 2
Output 1:
    113
Explanation 1:
    There are 2 number of students. Books can be distributed in following fashion : 
        1) [12] and [34, 67, 90]
        Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
        2) [12, 34] and [67, 90]
        Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
        3) [12, 34, 67] and [90]
        Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

        Of the 3 cases, Option 3 has the minimum pages = 113.

Input 2:
    A = [5, 17, 100, 11]
    B = 4
Output 2:
    100
    
*/
long long int find_sum(vector<int>& A)
{
    long long int sum=0;
    for(int i=0;i<A.size();i++)
    {
        sum+=A[i];
    }
    return sum;
}
long long int find_solution(vector<int>& A,long long int mid)
{
    long long int c=1;
   long long  int sum=0;
    for(int i=0;i<A.size();i++)
    {
        if(sum+A[i]<=mid)
        {
            sum+=A[i];
        }
        else
        {
            c++;
            sum=A[i];
        }
    }
    return c;
}
int Solution::books(vector<int> &A, int B) {
    int min1=*max_element(A.begin(),A.end());
    int max1=find_sum(A);
    long long int ans=0;
    if(B>A.size())
    return -1;
    while(min1<=max1)
    {
        long long  int mid=min1+(max1-min1)/2;
        
        long long int n1=find_solution(A,mid);
        if(n1<=B)
        {
            ans=mid;
            max1=mid-1;
        }
        else if(n1>B)
        {
            min1=mid+1;
        }
    }
    return ans;
}

