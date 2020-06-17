/*
Implement the next permutation, 
which rearranges numbers into the numerically next greater permutation of numbers.
 If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

For example:
1,2,3 ? 1,3,2
3,2,1 ? 1,2,3

*/
#include<bits/stdc++.h>
using namespace std;
vector<int> find_solution(vector<int>& vis)
{
    stack<int>s1;
    for(int i=0;i<vis.size();i++)
    {
        if(vis[i-1]>=vis[i])
          {
              if(i+1==vis.size())
              {
                  sort(vis.begin(),vis.end());
                  return vis;
              }
          }
          else
          break;
    }
    
    for(int i=vis.size()-1;i>=0;i--)
    {
                  if(vis[i-1]>=vis[i])
                  {
                      s1.push(i);
                  }
                  else
                  {
                      s1.push(i);
                      int t;
                      while(!s1.empty() && vis[i-1]<vis[s1.top()])
                      {
                          t=s1.top();
                          s1.pop();
                      }
                      swap(vis[i-1],vis[t]);
                      reverse(vis.begin()+i,vis.end());
                      return vis;
                  }
    }
    reverse(vis.begin(),vis.end());
    return vis;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>vis;
	    for(int i=0;i<n;i++)
	    {
	        int x;cin>>x;
	        vis.push_back(x);
	    }
	    vector<int>ans=find_solution(vis);
	    for(auto i:ans)
	    {
	        cout<<i<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
