/*
We have N persons sitting on a round table. Any person can do a handshake with any other person.

    1
2        3
    4
Handshake with 2-3 and 1-4 will cause cross.

In how many ways these N people can make handshakes so that no two handshakes crosses each other. N would be even. 

For example, in above diagram, there are two non-crossing ways to handshake {{1, 2}, {3, 4}} and {{1, 3}, {2, 4}}.


*/
#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
int find_solution(int n)
{
    if(n==0)
    return 1;
    int ans=0;
    if(dp[n]!=-1)
    return dp[n];
    for(int i=2;i<=n;i+=2)
    {
        ans+=find_solution(n-i)*find_solution(i-2);
    }
    return ans;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    dp.resize(n+1,-1);
	    cout<<find_solution(n)<<endl;
	    dp.clear();
	}
	return 0;
}
