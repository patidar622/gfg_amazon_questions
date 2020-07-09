/*
Given 2 integers A and B and an array of integars C of size N.

Element C[i] represents length of ith board.

You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of board.

Calculate and return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board.

2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.
Return the ans % 10000003

Input 1:
    A = 2
    B = 5
    C = [1, 10]
Output 1:
    50
Explanation 1:
    Possibility 1:- same painter paints both blocks, time taken = 55units
    Possibility 2:- Painter 1 paints block 1, painter 2 paints block 2, time take = max(5, 50) = 50
    There are no other distinct ways to paint boards.
    ans = 50%10000003

Input 2:
    A = 10
    B = 1
    C = [1, 8, 11, 3]
Output 2:
    11

*/
long long int find_sum(vector<int>& C)
{
    long long int sum=0;
    for(int i=0;i<C.size();i++)
    sum+=C[i];
    
    return sum;
}
long long int find_solution(vector<int>& C,int mid)
{
    long long int c=1;
    long long int sum=0;
    for(int i=0;i<C.size();i++)
    {
        if(C[i]>mid)
        return INT_MAX;
        if(sum+C[i]<=mid)
        {
            sum+=C[i];
        }
        else
        {
            sum=C[i];
            c++;
        }
    }
    return c;
}
int Solution::paint(int A, int B, vector<int> &C) {
   long long  int min1=*min_element(C.begin(),C.end());
    long long int max1=find_sum(C);
    long long int ans=0;
    
    while(min1<=max1)
    {
        long long int mid=min1+(max1-min1)/2;
        if(find_solution(C,mid)<=A)
        {
            ans=mid;
            max1=mid-1;
        }
        else
        {
            min1=mid+1;
        }
    }
    ans=(ans%10000003*B%10000003)%10000003;
    return ans;
}


