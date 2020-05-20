#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    string s1,s2;
	    cin>>s1>>s2;
	    int ans=INT_MAX;
	    int b[26]={0};
	    if(s2.size()>s1.size())
	 {   cout<<-1<<endl;
	}
	else{
	    for(int i=0;i<s2.size();i++)
	    {
	        b[s2[i]-'a']++;
	    }
	    int i=0;
	    int start=-1;
	    while(i<s1.size())
	    {
	        while(b[s1[i]-'a']==0)
	        {
	            i++;
	        }
	        int j=i;
	        int a[26]={0};
	        while(j<s1.size())
	        {
	            a[s1[j]-'a']++;
	            if(j-i+1>=s2.size())
	            {
	                int c=0;
	                for(int k=0;k<26;k++)
	                {
	                    if(b[k]!=0 && a[k]<b[k])
                  	 {  c=1;
	                    break;}
	                }
	                if(c==0)
	                {
	                   if(ans>j-i+1)
	                   {
	                       ans=j-i+1;
	                       start=i;
	                   }
	                   break;
	                }
	            }
	            j++;
	        }
	        i++;
	    }
	    if(start!=-1)
	    cout<<s1.substr(start,ans)<<endl;
	    else
	    cout<<-1<<endl;
	}
	}
	return 0;
}
