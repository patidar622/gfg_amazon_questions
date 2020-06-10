/*
Your Task:
You don't need to read input or print anything. 
Your task is to complete the function smallestWindow() which takes two string S and P as inputs and returns the smallest window in string S having all the characters of the string P.
In case there are multiple such windows of same length, return the one with the least starting index. Return "-1" in case there's no such window present. 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).


*/
string smallestWindow (string s, string p){
    int start=0,lenght=0;
    int a[26]={0};
    int b[26]={0};
    int startin=0;
    for(int i=0;i<p.size();i++)
    {
        a[p[i]-97]++;
    }
    int i=0;
    int ans=INT_MAX;
    int count=0;
    if(p.size()>s.size())
    return "-1";
    while(i<s.size())
    {
        b[s[i]-'a']++;
        if(a[s[i]-'a']!=0 && b[s[i]-'a']<=a[s[i]-'a'])
        count++;
        
        
        if(count==p.size())
        {
            while(b[s[start]-'a']>a[s[start]-'a']||a[s[start]-'a']==0)
            {
                if(b[s[start]-'a']>a[s[start]-'a'])
                {
                    b[s[start]-'a']--;
                }
                start++;
            }
        if(i-start+1<ans)
        {
            ans=i-start+1;
            startin=start;
        }
        }
        i++;
    }
    if(ans==INT_MAX)
    return "-1";
    string ans1=s.substr(startin,ans);
    return ans1;
}
