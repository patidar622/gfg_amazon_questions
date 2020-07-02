/*
Asked in:  
Google
You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times.
Problem Discussion
Solution Discussion
Access Hint
It works to simply pick all elements one by one. For every picked element, count its occurrences by traversing the array.
If count becomes more than n/3, then print the element. Time Complexity of this method would be O(n^2).

A better solution is to use sorting.

First, sort all elements using a O(nLogn) algorithm. All required elements in a linear scan of array can be found once the array is sorted.

So overall, time complexity of this method is O(nLogn) + O(n) which is O(nLogn).

However, a linear solution is needed here.

Note: if at any instance, you have three distinct elements from the array, if you remove them from the array, your answer does not change.

Try to base your solution idea on the above fact.

Would it help to maintain two elements from array with their count as you traversed the array ?


*/
int Solution::repeatedNumber(const vector<int> &A) {
    int  count1=0,count2=0;
    int first=INT_MAX,second=INT_MAX;
    int n=A.size();
    for(int i=0;i<A.size();i++)
    {
        if(first==A[i])
        {
            count1++;
        }
        else if(second==A[i])
        {
            count2++;
        }
        else if(count1==0)
        {
            count1++;
            first=A[i];
        }
        else if(count2==0)
        {
            count2++;
            second=A[i];
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1=0;
    count2=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==first)
        count1++;
        else if(A[i]==second)
        count2++;
    }
    if(count1>n/3)
    return first;
    if(count2>n/3)
    return second;
    return -1;
}

