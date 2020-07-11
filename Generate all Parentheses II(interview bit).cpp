/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.

*/
vector<string>ans;
void find_solution(int A,string s,int open,int close)
{
    if(s.size()==2*A)
    {
        ans.push_back(s);
        return;
    }
    if(open<A && open>=close){
    s.push_back('(');
    find_solution(A,s,open+1,close);
    s.pop_back();
    }
    if(close<A && open>close)
    {
        s.push_back(')');
        find_solution(A,s,open,close+1);
        s.pop_back();
    }
    return;
}
vector<string> Solution::generateParenthesis(int A) {
    string s="";
    ans.clear();
    find_solution(A,s,0,0);
    sort(ans.begin(),ans.end());
    return ans;
}

