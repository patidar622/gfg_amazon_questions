/*
A string is said to be a special string if either of two conditions is met:
All of the characters are the same, e.g. aaa.
All characters except the middle one are the same, e.g. aadaa.
A special substring is any substring of a string which meets one of those criteria. Given a string, determine how many special substrings can be formed from it.

For example, given the string , we have the following special substrings: .

Function Description

Complete the substrCount function in the editor below. It should return an integer representing the number of special substrings that can be formed from the given string.

substrCount has the following parameter(s):

n: an integer, the length of string s
s: a string
Input Format

The first line contains an integer, , the length of .
The second line contains the string .

Constraints


Each character of the string is a lowercase alphabet, .

Output Format

Print a single line containing the count of total special substrings.

Sample Input 0

5
asasd
Sample Output 0

7 
Explanation 0

The special palindromic substrings of  are 

Sample Input 1

7
abcbaba
Sample Output 1

10 
Explanation 1

The special palindromic substrings of  are 

Sample Input 2

4
aaaa
Sample Output 2

10
*/
//function problem he


long substrCount(int n, string s) {
    long ans=0;
   int i=0;
   int same_char[n]={0};
   while(i<n)
   {
       int j=i+1,c=1;
       while(j<n && s[i]==s[j])
       {
           j++;
           c++;
       }
       ans+=(c*(c+1))>>1;
       same_char[i]=c;
       i=j;
   }
   
   for(int j=1;j<n-1;j++)
   {
       if(s[j]==s[j-1])
       {
           same_char[j]=same_char[j-1];
       }

       if(s[j-1]==s[j+1] && s[j]!=s[j-1])
       ans+=min(same_char[j-1],same_char[j+1]);
   }

return ans;
}

