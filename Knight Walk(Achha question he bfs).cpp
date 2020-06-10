/*
Given a chess board of order N x M and source points (s1, s2) and destination points (d1, d2). 
The task to find minimum number of moves required by the Knight to go to the destination cell.

Input:
The first line of input contains an integer T denoting the number of testcases. 
Then T test cases follow. Each test case contains two lines. 
The first line of each testcase contains two space separated integers N and M.
 Then in the next line are four space separated values s1, s2 and d1, d2.

Output:
For each testcase in a new line print the minimum number of moves required by the knight to go to the destination from the source.
If no such move is possible print -1.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    int i1,j1,i2,j2;
	    cin>>i1>>j1>>i2>>j2;
	    i1--;
	    j1--;
	    i2--;
	    j2--;
	    int count=0;
	    queue<pair<int,int>>q1;
	    q1.push({i1,j1});
	    q1.push({-1,-1});
	    vector<vector<int>>dp(n,vector<int>(m,-1));
	    dp[i1][j1]=1;
	    int c=0;
	    int dis[8][2]={{1,2},{-1,2},{2,1},{2,-1},{-2,1},{-2,-1},{1,-2},{-1,-2}};
	    while(q1.front().first!=-1)
	    {
	       
	        while(q1.front().first!=-1)
	        {
	            pair<int,int>p1=q1.front();
	            q1.pop();
	            if(p1.first==i2 && p1.second==j2)
	           { cout<<count<<endl;
	            c=1;
	            break;}
	            for(int i=0;i<8;i++)
	            {
	                int new_r=p1.first+dis[i][0];
	                int new_c=p1.second+dis[i][1];
	                
	                if(new_r>=0 && new_r<n && new_c>=0 && new_c<m && dp[new_r][new_c]==-1)
	                {
	                    dp[new_r][new_c]=1;
	                    q1.push({new_r,new_c});
	                }
	                
	            }
	        }
	        if(c==1)
	        break;
	         count++;
	         q1.pop();
	         q1.push({-1,-1});
	        
	    }
	    if(c==0)
	    cout<<-1<<endl;
	}
	return 0;
}
