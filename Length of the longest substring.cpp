#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int start=0,i=0;
	    map<char,int>m1;
	    int ans=0,c=0;
	    while(i<s.size())
	    {
	        if(m1.find(s[i])==m1.end())
	        {
	             c++;
	        }
	        else{
	            ans=max(ans,c);
	            i=m1[s[i]]+1;
	            c=1;
	            m1.clear();
	        }
	        m1[s[i]]=i;
	        i++;
	        ans=max(ans,c);
	    }
	    ans=max(ans,c);
	    cout<<ans<<endl;
	}
	return 0;
}
