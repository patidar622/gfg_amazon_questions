/*Given arrival and departure times of all trains that reach a railway station. 
Your task is to find the minimum number of platforms required for the railway station so that no train waits.

Note: Consider that all the trains arrive on the same day and leave on the same day.
 Also, arrival and departure times will not be same for a train, but we can have arrival time of one train equal to departure of the other.
 In such cases, we need different platforms, i.e at any given instance of time, same platform can not be used for both departure of a train and arrival of another
*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>a,b;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        a.push_back(x);
	    }
	     for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        b.push_back(x);
	    }
	    vector<pair<int,int>>p1;
	    for(int i=0;i<n;i++)
	    {
	        p1.push_back({a[i],b[i]});
	    }
	    sort(p1.begin(),p1.end());
	    int ans=0;
	    priority_queue<int,vector<int>,greater<int>>q1;
	    for(int i=0;i<n;i++)
	    {
	        if(q1.size()==0)
	        {
	            q1.push(p1[i].second);
	        }
	        else
	        {
	            if(p1[i].first<=q1.top())
	            {
	                q1.push(p1[i].second);
	            }
	            else if(p1[i].first>q1.top())
	            {
	                while(!q1.empty() && p1[i].first>q1.top())
	                {
	                    q1.pop();
	                }
	                q1.push(p1[i].second);
	            }
	        }
	        int i1=q1.size();
	        ans=max(ans,i1);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
