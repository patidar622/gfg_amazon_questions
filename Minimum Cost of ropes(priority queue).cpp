/*
There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	     priority_queue<int,vector<int>,greater<int>>q1;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        q1.push(x);
	    }
	    long long int ans=0;
	   while(q1.size()!=1)
	   {
	       int i1=q1.top();q1.pop();
	       int i2=q1.top();q1.pop();
	       int sum=i1+i2;
	       ans+=sum;
	       q1.push(sum);
	   }
	   cout<<ans<<endl;
	}
	return 0;
}
