/*
You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.

*/
vector<int> Solution::subUnsort(vector<int> &A) {
   //Method 3 - 
   //By finding smallest element after sorted subarray from left, 
   //and largest element before sorted subarray from right
   //Time=O(n), Space=O(1)
    int i=0,j=A.size()-1,minn,maxx;
    int n=A.size();
    vector<int>ans;
    while(i<n-1 && A[i]<=A[i+1])
    i++;
    if(i==n-1)
    ans.push_back(-1);
    else
    {
        minn=min_element(A.begin()+i+1,A.end())-A.begin();
        while(i>=0 && A[i]>A[minn])
        i--;
        
        while(j>0 && A[j]>=A[j-1])
        j--;
        
        maxx=max_element(A.begin()+0,A.begin()+j)-A.begin();
        while(j<n && A[j]<A[maxx])
        j++;
        
        ans.push_back(i+1);
        ans.push_back(j-1);
    }
    return ans; 
    /*
    // time o(n^2) so it gives tle but working fine o(n) space
    vector<int>vis(A.size(),-1);
    int min_in=A.size()-1;
    for(int i=0;i<A.size()-1;i++)
    {
        min_in=-1;
        for(int j=i+1;j<A.size();j++)
        {
            if(A[i]>A[j])
            min_in=j;
        }
        vis[i]=min_in;
    }
    int start=A.size(),end=-1;
    for(int i=0;i<A.size();i++)
    {
        if(vis[i]!=-1 && A[i]>A[vis[i]])
        {
                start=min(start,i);
                end=max(end,vis[i]);
        }
    }
     vector<int>ans;
    if(end==-1)
    {
        ans.push_back(-1);
        return ans;
    }
    ans.push_back(start);
    ans.push_back(end);
    return ans;
    */
}

