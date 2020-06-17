/*
Given K sorted arrays arranged in the form of a matrix of size K*K. 
The task is to merge them into one sorted array.
Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)
*/
typedef pair<int,pair<int,int>> pp1;
int *mergeKArrays(int arr[][N], int k)
{
    int *arr1=new int[k*k];
    priority_queue<pp1,vector<pp1>,greater<pp1>>q1;
    for(int i=0;i<k;i++)
    {
        q1.push({arr[i][0],{i,0}});
    }
    int k2=0;
    while(!q1.empty())
    {
        pp1 p1=q1.top();
        q1.pop();
        int i1=p1.first;
        int r1=p1.second.first;
        int k1=p1.second.second;
        arr1[k2++]=i1;
        if(k1<k-1)
        {
        q1.push({arr[r1][k1+1],{r1,k1+1}});
        }
    }
    return arr1;
        
}
