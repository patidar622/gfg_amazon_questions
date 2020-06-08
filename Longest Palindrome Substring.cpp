string longestPalindrome(string A) {
    string ans="";
    int start=0;
    int len=1;
    vector<vector<int>>dp(A.size(),vector<int>(A.size(),0));
    for(int i=0;i<A.size();i++)
    {
        dp[i][i]=1;
    }
    int c=0;
    for(int i=1;i<A.size();i++)
    {
        if(A[i]==A[i-1])
        {dp[i-1][i]=1;
        if(c==0){
            c=1;
        start=i-1;
        len=2;
        }
        }
    }
    for(int k=3;k<=A.size();k++)
    {
        int i=0;
        while(i<A.size()-k+1)
        {
            int j=i+k-1;
            if(A[i]==A[j] && dp[i+1][j-1]==1)
            {
                dp[i][j]=1;
                if(len<(j-i+1))
                {
                    len=j-i+1;
                    start=i;
                }
            }
            i++;
        }
    }
    return A.substr(start,len);
}
