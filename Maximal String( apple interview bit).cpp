/*
Problem Description

Given a string A and integer B, what is maximal lexicographical stringthat can be made from A if you do atmost B swaps.



Problem Constraints
1 <= |A| <= 9

A contains only digits from 0 to 9.

1 <= B <= 5



Input Format
First argument is string A.

Second argument is integer B.



Output Format
Return a string, the naswer to the problem.



Example Input
Input 1:

A = "254"
B = 1
Input 2:

A = "254'
B = 2


Example Output
Output 1:

 524
Output 2:

 542


Example Explanation
Explanation 1:

 Swap 2 and 5.
Explanation 2:

Swap 2 and 5 then swap 4 and 2.
*/
string ans;
void find_solution(string A,int B,int i)
{
    if(i==A.size() || B==0)
    {
        ans=max(ans,A);
        return;
    }
    if(B>0)
    {
        ans=max(ans,A);
    }
    if(i>A.size() || B<0)
    return;
    for(int i1=i+1;i1<A.size();i1++)
    {
        if(A[i]<A[i1])
        {
            swap(A[i],A[i1]);
            find_solution(A,B-1,i+1);
            swap(A[i],A[i1]);
        }
        else
        {
            find_solution(A,B,i+1);
        }
    }
    return;
}
string Solution::solve(string A, int B) {
ans="";

find_solution(A,B,0);
return ans;
}

