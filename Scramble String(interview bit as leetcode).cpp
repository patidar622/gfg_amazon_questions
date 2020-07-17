/*Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of A = “great”:


    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.



Given two strings A and B of the same length, determine if B is a scrambled string of S.



Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= len(A), len(B) <= 50
Examples:

Input 1:
    A = "we"
    B = "we"

Output 1:
    1

Input 2:
    A = "phqtrnilf"
    B = "ilthnqrpf"
    
Output 2:
    0
    */
  //this problem can oly be solve with mp only its to complicated to maintain the dp table  
unordered_map<string,bool>m1;

bool find_solution(string A,string B)
{
    if(A==B)
    return true;
    if(A.size()<=1)
    return false;
   string s=A;
   s.push_back('_');
   s+=B;
   if(m1.find(s)!=m1.end())
   return m1[s];
    bool flag=false;
    for(int i=1;i<A.size();i++)
    {
        if((find_solution(A.substr(0,i),B.substr(0,i)) && find_solution(A.substr(i,A.size()-i),B.substr(i,A.size()-i)))
        || (find_solution(A.substr(0,i),B.substr(A.size()-i,i)) && find_solution(A.substr(i,A.size()-i),B.substr(0,A.size()-i))))
        return m1[s]=true;
        
    }
    return m1[s]=false;
}
int Solution::isScramble(const string A, const string B) {
    if(A.size()!=B.size())
    return false;
    m1.clear();
    return find_solution(A,B);
}

