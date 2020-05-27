#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
int find_solution(string s,int i,set<string>s1,set<int>s2)
{
    if(i==s.size())
    return 1;
    if(dp[i]!=-1)
    return dp[i];
    
    int ans=0;
    for(auto j:s2)
    {
        if(i+j<=s.size()){
        string ss1=s.substr(i,j);
        if(s1.find(ss1)!=s1.end())
        {
            ans=find_solution(s,i+j,s1,s2);
            if(ans==1)
              break;
        }
    }
    }
    return dp[i]=ans;
}
int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	      set<string>s1;
         set<int>s2;
	    for(int i=0;i<n;i++)
	    {
	        string s;
	        cin>>s;
	        s1.insert(s);
	        s2.insert(s.size());
	    }
	    string s;
	    cin>>s;
	     dp.resize(s.size()+1,-1);
	    if(find_solution(s,0,s1,s2))
	    cout<<1<<endl;
	    else
	    cout<<0<<endl;
	    dp.clear();
	}
	return 0;
}
