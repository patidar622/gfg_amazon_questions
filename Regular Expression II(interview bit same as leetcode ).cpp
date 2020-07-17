/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Some examples:

isMatch("aa","a") ? 0
isMatch("aa","aa") ? 1
isMatch("aaa","aa") ? 0
isMatch("aa", "a*") ? 1
isMatch("aa", ".*") ? 1
isMatch("ab", ".*") ? 1
isMatch("aab", "c*a*b") ? 1
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/
vector<vector<bool>>dp;
bool find_solution(const string& A,const string& B,int i,int j)
{
    if(i==A.size() && j==B.size())
    {
        return true;
    }
    if(dp[i][j]==false)
    return dp[i][j];
    int c=0;
    if(A[i]==B[j] || B[j]=='.')
    {
        c=1;//isme check kar liya ki char same he ki nahi kabhi nahi hoga toh c=0
    }
    if(j+1<B.size() && B[j+1]=='*')//isme dekhnge ki next char b me * he toh uske pahle wale sab same prefix ho jayenge match or kabhi * nahi hua toh dekhenge ki c==1 he matalab ki char same he toh humko pta he ki next wala * he B me toh ham A me i ko increase karke dekhnege ki next wala or abhi jo j me he wo same he kio nahi
    return dp[i][j]=find_solution(A,B,i,j+2) || (i+1<=A.size() && (c==1) && find_solution(A,B,i+1,j));
    else 
    return dp[i][j]=(i+1<=A.size() && c==1 && find_solution(A,B,i+1,j+1));// isme hame pta he ki c==1 he toh char same he or next * bhi nahi he toh simple dono ko 1 1 increase karke dekhneg aage kya hota he
    
    return dp[i][j]=false;
}
int Solution::isMatch(const string A, const string B) {
    if(A.size()==0 && B.size())
    return false;
    dp.clear();
    dp.resize(A.size()+1,vector<bool>(B.size()+1,true));
    return find_solution(A,B,0,0);
}

