#include<bits/stdc++.h>
using namespace std;
int main()
 {
	   int t;cin>>t;
	   while(t--)
	   {
	       int n,m;
	       cin>>n>>m;
	       vector<vector<int> >vis(n,vector<int>(m,0));
	       vector<vector<int> >dp(n,vector<int>(m,0));
	       queue<pair<int,int>>q1;
	       for(int i=0;i<n;i++)
	       {
	           for(int j=0;j<m;j++)
	           {
	               int x;
	               cin>>x;
	               if(x==2)
	               {q1.push({i,j});
	               dp[i][j]=1;}
	               vis[i][j]=x;
	           }
	       }
	       int dis[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
	       q1.push({-1,-1});
	       int count=0;
	       while(q1.front().first!=-1)
	       {
	           count++;
	           while(q1.front().first!=-1)
	           {
	               pair<int,int>p1=q1.front();
	               q1.pop();
	               for(int i=0;i<4;i++)
	               {
	                   int new_r=p1.first+dis[i][0],new_c=p1.second+dis[i][1];
	                   if(new_r>=0 && new_r<n && new_c>=0 && new_c<m && vis[new_r][new_c]==1 && dp[new_r][new_c]==0)
	                   {
	                       vis[new_r][new_c]=2;
	                       dp[new_r][new_c]=1;
	                       q1.push({new_r,new_c});
	                   }
	               }
	           }
	           q1.pop();
	           q1.push({-1,-1});
	       }
	       int c=0;
	       for(int i=0;i<n;i++)
	       {
	           for(int j=0;j<m;j++)
	           {
	               if(vis[i][j]==1)
	              {    c=1;
	               break;}
	           }
	           if(c==1)
	           break;
	       }
	       if(c==0)
	      cout<<count-1<<endl;
	      else 
	      cout<<-1<<endl;
	   }
	return 0;
}
