/*
Given an array A[] of N positive integers which can contain integers from 1 to N where
 elements can be repeated or can be absent from the array. 
 Your task is to count frequency of all elements from 1 to N.

Note: Expected time complexity is O(n) with O(1) extra space.


 ****** main logic ******
1)  Subtract 1 from every element so that the elements
    become in range from 0 to n-1
    for (int j =0; j < n; j++)
        arr[j] = arr[j]-1;

2)  Use every element arr[i] as index and add 'n' to
    element present at arr[i]%n to keep track of count of
    occurrences of arr[i]
    for (int i=0; i < n; i++)
        arr[arr[i]%n] = arr[arr[i]%n] + n;

3)  To print counts, simply print the number of times n
    was added at index corresponding to every element
    for (int i =0; i < n; i++)
        print "(i + 1) -> arr[i] " 

*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>vis;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        vis.push_back(x-1);
	    }
	    for(int i=0;i<n;i++)
	    {
	        vis[vis[i]%n]=vis[vis[i]%n]+n;
	    }
	    for(int i=0;i<n;i++)
	    {
	        cout<<vis[i]/n<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
