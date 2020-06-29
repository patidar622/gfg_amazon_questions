/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], 
reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. 
For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.




*/
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tic) {
        unordered_map<string,multiset<string> >m1;
        for(int i=0;i<tic.size();i++)
        {
            m1[tic[i][0]].insert(tic[i][1]);
        }
        stack<string>ss1;
        vector<string>ans;
        string start="JFK";
          ss1.push(start);
        while(!ss1.empty())
        {
            start=ss1.top();
            if(m1[start].size()==0)
            {
                ans.push_back(start);
                ss1.pop();
            }
            else
            {
               
                auto i1=m1[start].begin();
                ss1.push(*i1);
                m1[start].erase(i1);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
