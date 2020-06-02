#include<bits/stdc++.h>
using namespace std;
string find_solution(string s)
{
    stack<char>s1;
    string ans="";
    map<char,int>m1;
    m1['+']=1;
    m1['-']=1;
    m1['*']=2;
    m1['/']=2;
    m1['^']=4;
    for(int i=0;i<s.size();i++)
    {
        if(isalpha(s[i]))
        ans+=s[i];
        else if(s1.empty() || s[i]=='(')
        s1.push(s[i]);
        else if(s[i]==')')
        {
            while(s1.top()!='(')
            {
                ans+=s1.top();
                s1.pop();
            }
            s1.pop();
        }
        else if(m1[s[i]]<=m1[s1.top()])
        {
            while(!s1.empty() && m1[s[i]]<=m1[s1.top()])
            {
                ans+=s1.top();
                s1.pop();
            }
            s1.push(s[i]);
        }
        else
        {
            s1.push(s[i]);
        }
    }
    while(!s1.empty())
    {
        ans+=s1.top();
        s1.pop();
    }
    return ans;
}
int main()
 {
      int t;
      cin>>t;
      while(t--)
      {
          string s;
          cin>>s;
          string ans=find_solution(s);
          cout<<ans<<endl;
      }
	return 0;
}
