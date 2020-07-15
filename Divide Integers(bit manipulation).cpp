/*
ivide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.

Note: INT_MAX = 2^31 - 1


*/
int Solution::divide(int A, int B) {
    if(A==INT_MIN && B==-1)
    return INT_MAX;
    if(A==INT_MIN && B==1)
    return INT_MIN;
    if(A==0)
    return 0;
    long long  int n=A;
    long long int m=B;
    long long int sign=((n<0)^(m<0)) ? -1 : 1;
   n=abs(n);
   m=abs(m);
    long long int t=0,q=0;
    for(int i=31;i>=0;--i)
    {
        if(t+(m<<i)<=n)
        {
            t+=(m<<i);
            q|=((1LL)<<i);
        }
    }
    if(sign<0)
    q=q*(-1);
return (q>=INT_MAX || q<INT_MIN) ? INT_MAX : q;    
    
    
}

