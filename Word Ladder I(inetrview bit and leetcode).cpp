/*
Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:

You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains an array of strings, C.
Output Format:

Return an integer representing the minimum number of steps required to change string A to string B.
Constraints:

1 <= length(A), length(B), length(C[i]) <= 25
1 <= length(C) <= 5e3
Example :

Input 1:
    A = "hit"
    B = "cog"
    C = ["hot", "dot", "dog", "lot", "log"]

Output 1:
    5

Explanation 1:
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"


*/
int Solution::solve(string A, string B, vector<string> &C) {
    unordered_map<string ,int>m1;
  unordered_map<string,int>m2;
    for(int i=0;i<C.size();i++)
    {
        m1[C[i]]=1;
    }
    string start1=A,end1=B;
    queue<string>q1;
    q1.push(start1);
    q1.push("google");
    
    m2[start1]=1;
    int count=1;
    while(q1.front()!="google")
    {
        while(q1.front()!="google")
        {
            string s=q1.front();q1.pop();
            if(s==end1)
            return count;
            for(int i1=0;i1<s.size();i1++)
            {
                char l1=s[i1];
               for(int k=0;k<26;k++)
                {
                    s[i1]='a'+k;
                    if(m1.find(s)!=m1.end() && m2.find(s)==m2.end()){
                    m2[s]=1;
                    q1.push(s);
                    }
                }
                s[i1]=l1;
            }
        }
        q1.pop();
        q1.push("google");
        count++;
    }
    return  0;
}

