#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	   bool b[256]={false};
	    int c=0;
	    for(int i=0;i<s.size();i++)
	    {
	        if(b[s[i]]==false)
	       { b[s[i]]=true;
	        c++;}
	    }
	    int a[256]={0};
	    int ans=INT_MAX;
	    int i=0,start=0,count=0;
	    while(i<s.size())
	    {
	        a[s[i]]++;
	        if(a[s[i]]==1)
	        count++;
	        
	        if(count==c)
	        {
	                while(a[s[start]]>1)
	                {
	                     if(a[s[start]]>1)
	                       a[s[start]]--;
	                    start++;
	                }
	                 if(i-start+1<ans)
	                 ans=i-start+1;
	        }
	       
	        i++;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
