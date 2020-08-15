/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
         unordered_set<char>s1;
        int i=0,j=0;
        while(i<s.size() && j<s.size())
        {
            if(s1.count(s[j])==0)
            {
                s1.insert(s[j++]);
                int i1=s1.size();
                ans=max(ans,i1);
            }
            else
                s1.erase(s[i++]);
        }
        return ans;
    }
};
