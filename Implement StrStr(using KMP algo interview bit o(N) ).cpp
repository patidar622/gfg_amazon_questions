/*
Implement strStr().
 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. 
*/
int Solution::strStr(const string A, const string B) {
    if(B.size()==0)
    return -1;
    if(B.size()>A.size())
    return -1;
    if(A.size()==0)
    return -1;
    vector<int>vis(B.size(),0);
    int i=0,j=1;
    vis[0]=0;
    while(j<B.size())
    {
        if(B[i]==B[j])
        {
            vis[j]=i+1;
            i++;
            j++;
        }
        else
        {
            if(i>=1)
            {
                i=vis[i-1];
            }
            else
            {
                vis[j]=0;
                j++;
            }
        }
    }
    j=0,i=0;
    while(i<A.size())
    {
        
        if(A[i]==B[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j>=1)
            j=vis[j-1];
            else
            i++;
        }
        if(j==B.size())
        return i-B.size();
    }
    return -1;
}

