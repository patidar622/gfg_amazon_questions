/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

 Note:
If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).

*/
string Solution::minWindow(string A, string B) {
    map<char,int>m1,m2;
    for(int i=0;i<B.size();i++)
    {
        m2[B[i]]++;
    }
    string ans="";
    int i=0,j=-1;
    int ans1=INT_MAX,count=0;
    while(++j<A.size())
    {
       if(++m1[A[j]]<=m2[A[j]])
        count++;
        
        if(count<B.size())continue;
        
            while(m1[A[i]]>m2[A[i]])
            {
                m1[A[i]]--;
                i++;
            }
        if(ans1>j-i+1)
        {
            ans1=j-i+1;
            ans=A.substr(i,ans1);
        }
    }
    return ans;
}

