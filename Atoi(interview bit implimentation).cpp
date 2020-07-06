/*
Please Note:
There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
*/
int Solution::atoi(const string A) {
    long long int ans;
    int i=0;
    while(i<A.size() && A[i]==32)
    {
        i++;
    }
    int c=0;
    if(i==A.size())
    return 0;
    int j=i;
    if(A[j]=='-')
    {j++;
    i++;
    c=1;}
    if(A[j]=='+')
    {
        i++;
        j++;
        c=0;
    }
    while(j<A.size() && isdigit(A[j]))
    {
        j++;
    }
    if(j==i)
    return 0;
    string s=A.substr(i,j-i);
    ans=0;
    for(int i=0;i<s.size();i++)
    {
        ans=ans*10+(int)(s[i]-'0');
        if(c==1 && ans>INT_MAX)
        return INT_MIN;
        if(c==0 && ans>INT_MAX)
        return INT_MAX;
    }
    if(c==1)
    ans=-1*ans;
    return ans;
}

