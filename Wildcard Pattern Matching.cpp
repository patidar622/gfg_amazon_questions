vector<vector<int>>dp;
int find_solution(string pat,string str,int i,int j)
{
    if(i==pat.size() && j==str.size())
    return 1;
    if(i>pat.size() || j>str.size())
    return 0;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    if(pat[i]==str[j] || str[j]=='?')
    return dp[i][j]=find_solution(pat,str,i+1,j+1);
    else if(str[j]=='*')
    return dp[i][j]=find_solution(pat,str,i,j+1)||find_solution(pat,str,i+1,j+1)||find_solution(pat,str,i+1,j);
}
int wildCard(string str,string pat)
{
    dp.clear();
    dp.resize(pat.size()+1,vector<int>(str.size()+1,-1));
    return find_solution(pat,str,0,0);
}
