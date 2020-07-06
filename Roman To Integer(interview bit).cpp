/*
Given a string A representing a roman numeral.
Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more
details about roman numerals at Roman Numeric System



Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.
For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20


*/
int Solution::romanToInt(string A) {
/*    Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

*/
int n=0;
for(int i=0;i<A.size();i++)
{
    if(i!=A.size()-1 && A[i]=='I' && A[i+1]=='V')
    {
        n+=4;
        i++;
    }
    else if(i!=A.size()-1 && A[i]=='I' && A[i+1]=='X')
    {
        n+=9;
        i++;
    }
    else if(A[i]=='I')
    {
        n+=1;
    }
    else if(A[i]=='V')
    {
        n+=5;
    }
    else if(i!=A.size()-1 && A[i]=='X' && A[i+1]=='L')
    {
        n+=40;
        i++;
    }
    else if(i!=A.size()-1 && A[i]=='X' && A[i+1]=='C')
    {
        n+=90;
        i++;
    }
    else if(A[i]=='X')
    {
        n+=10;
    }
    else if(A[i]=='L')
    {
        n+=50;
    }
    else if(i!=A.size()-1 && A[i]=='C' && A[i+1]=='D')
    {
        n+=400;
        i++;
    }
    else if(i!=A.size()-1 && A[i]=='C' && A[i+1]=='M')
    {
        n+=900;
        i++;
    }
    else if(A[i]=='C')
    {
        n+=100;
    }
    else if(A[i]=='D')
    {
        n+=500;
        
    }
    else if(A[i]=='M')
    {
        n+=1000;
    }
}
return n;
}

