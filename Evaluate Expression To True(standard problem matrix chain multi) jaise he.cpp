/*
Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?

Operands are only true and false.

Return the number of ways to evaluate the expression modulo 103 + 3.



Input Format:

The first and the only argument of input will contain a string, A.

The string A, may contain these characters:
    '|' will represent or operator 
    '&' will represent and operator
    '^' will represent xor operator
    'T' will represent true operand
    'F' will false
Output:

Return an integer, representing the number of ways to evaluate the string.
Constraints:

1 <= length(A) <= 150
Example:

Input 1:
    A = "T|F"

Output 1:
    1

Explanation 1:
    The only way to evaluate the expression is:
        => (T|F) = T 

Input 2:
    A = "T^T^F"
    
Output 2:
    0
    
Explanation 2:
    There is no way to evaluate A to a true statement.

*/
unordered_map<string,int>m1;
int find_solution(string A,int i,int j,int is_true)
{
    if(i>j)
    return 0;
    if(i==j)
    {
        if(is_true==1)
        return A[i]=='T';
        else
        return A[i]=='F';
    }
    string s1=to_string(i);
    s1.push_back(' ');
    s1+=to_string(j);
    s1.push_back(' ');
    s1+=to_string(is_true);
    
    if(m1.find(s1)!=m1.end())
    return m1[s1];
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2)
    {
        int left_true=find_solution(A,i,k-1,1);
        int left_false=find_solution(A,i,k-1,0);
        int right_true=find_solution(A,k+1,j,1);
        int right_false=find_solution(A,k+1,j,0);
        
        
        if(A[k]=='|')
        {
            if(is_true==1)
            ans=(ans+left_true*right_true+left_true*right_false+left_false*right_true)%1003;
            else
            ans=(ans+left_false*right_false)%1003;
        }
        if(A[k]=='^')
        {
            if(is_true==1)
            ans=(ans+left_true*right_false+left_false*right_true)%1003;
            else
            ans=(ans+left_false*right_false+left_true*right_true)%1003;
        }
        if(A[k]=='&')
        {
            if(is_true==1)
            ans=(ans+left_true*right_true)%1003;
            else
            ans=(ans+left_false*right_true+left_false*right_false+left_true*right_false)%1003;
        }
    }
    return m1[s1]=ans%1003;
}
int Solution::cnttrue(string A) {
    m1.clear();
     if(A.size()==0)
     return 0;
    return find_solution(A,0,A.size()-1,1);
}


