/*
Problem Description

Given an integer A you need to find the Ath fibonacci number modulo 109 + 7.

The first fibonacci number F1 = 1

The first fibonacci number F2 = 1

The nth fibonacci number Fn = Fn-1 + Fn-2 (n > 2)



Problem Constraints
1 <= A <= 109.



Input Format
First argument is an integer A.



Output Format
Return a single integer denoting Ath fibonacci number modulo 109 + 7.
*/
long long int m=1000000007;
vector<long> mul(vector<long> m1,vector<long> m2)
{
    for(int i=0;i<4;i++)
    {
        m1[i]=m1[i]%m;
        m2[i]%=m;
    }
    
    vector<long>arr={0,0,0,0};
    
    arr[0]=(m1[0]*m2[0])%m +(m1[1]*m2[2])%m;
    arr[1]=(m1[0]*m2[1])%m +(m1[1]*m2[3])%m;
    arr[2]=(m1[2]*m2[0])%m +(m1[3]*m2[2])%m;
    arr[3]=(m1[2]*m2[1])%m +(m1[3]*m2[3])%m;
    
    return arr;
}

vector<long> find_solution(vector<long> arr,int n)
{
    if(n==1)
    return arr;
    vector<long>n1=arr;
    arr=find_solution(arr,n/2);
    
    arr=mul(arr,arr);
    
    if(n%2!=0)
    arr=mul(arr,n1);
    
    return arr;
}
int Solution::solve(int A) {
    /*
    time o(n) but gives tle 
    long long int f1=1,f2=1,m=1000000007;
    for(long long int i=3;i<=A;i++)
    {
        long long int sum=(f1+f2)%m;
        f1=f2;
        f2=sum;
    }
    return f2;
    */
    // time o(log(n))
    /*
    logic 
    If we n times multiply the matrix M = {{1, 1},{1, 0}} to itself (in other words calculate power(M, n )), 
	then we get the (n+1)th Fibonacci number as the element at row and column (0, 0) in the resultant matrix.

Use this fact and try to find a solution to the problem.
    
    */
    if(A<=2)
    return 1;
    vector<long>arr={1,1,1,0};
    
    arr=find_solution(arr,A-1);
    return  arr[0]%m;
}

