/*
Given a text and a pattern. 
Find whether the pattern exist in the text or not. If it is present print "found" without quotes else print "not found"
without quotes.

Input:

*/
#include<bits/stdc++.h>
using namespace std;
bool find_solution(string s,string p) // this function is using rolling hash technique very important pattern matching algo ::
{
    int p1=p.size();
    if(p.size()>s.size())
    return false;
    int hash=0;
    for(int i=0;i<p.size();i++)
    {
        hash=((hash*26)+p[i]-'a')%26;
    }
    
    int hash1=0;
    for(int i=0;i<p.size();i++)
    {
        hash1=((hash1*26)+s[i]-'a')%26;
    }
    if(hash1==hash)
   {       string ss1=s.substr(0,p1);
            if(p.compare(ss1)==0)
             return true;
    }
    for(int i=p.size();i<s.size();i++)
    {
        hash1=hash1-((int)pow((double)26,(double)p1-1)*(s[i-p1]-'a'))%26;
        hash1=(hash1*26 +s[i]-'a')%26;
        
        if(hash1==hash)
        {
            string ss1=s.substr(i-p1+1,p1);
            if(p.compare(ss1)==0)
             return true;
            
        }
    }
    return false;
}
int main()
 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    string s,p;
	    cin>>s>>p;
	    
	    if(find_solution(s,p))
	    cout<<"found"<<endl;
	    else
	    cout<<"not found"<<endl;
	}
	return 0;
}
