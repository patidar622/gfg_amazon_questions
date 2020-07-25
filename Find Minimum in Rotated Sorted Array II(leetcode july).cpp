/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?


*/
class Solution {
public:
    int find_solution(vector<int>&nums,int i,int j)
    {
       if(i==j)
           return nums[i];
        int mid=i+(j-i)/2;
        if(nums[i]==nums[mid] && nums[mid]==nums[j])
            return min(find_solution(nums,i,mid),find_solution(nums,mid+1,j));
        else if(nums[i]<=nums[mid])
            return min(nums[i],find_solution(nums,mid+1,j));
        else 
            return min(nums[mid],find_solution(nums,i,mid-1));    
    }
    int findMin(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        return find_solution(nums,0,nums.size()-1);
    }
};

