/*
Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:

Absolute path always begin with ’/’ ( root directory ).

Path will not have whitespace characters.



Input Format

The only argument given is string A.
Output Format

Return a string denoting the simplified absolue path for a file (Unix-style).
For Example

Input 1:
    A = "/home/"
Output 1:
    "/home"
    
    
    **** hint****
    More of a simulation problem.
Break the string along ‘/’ and process the substrings in order one by one. ‘..’ indicates popping an entry unless there is nothing to pop
	*/
string Solution::simplifyPath(string A) {
    stack<string> s1;
    
    string s3=".";
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='/')
        continue;
        else
        {
            string s2="";
            while(i<A.size() && A[i]!='/')
            {
                s2+=A[i];
                i++;
            }
            if(s2=="..")
            {
                if(!s1.empty())
                s1.pop();
            }
            else if(s2==s3)
            continue;
            else
            {
                s1.push(s2);
            }
        }
    }
     
    if(s1.empty())
    {
       string sw="/";
       return sw;
    }
    string ans="";
    while(!s1.empty())
    {
        string temp=s1.top();
        reverse(temp.begin(),temp.end());
        ans+=temp;
       ans+='/';
       s1.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

