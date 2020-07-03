/*
Problem Description

A hotel manager has to process N advance bookings of rooms for the next season. His hotel has C rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .



Input Format
First argument is an integer array A containing arrival time of booking.
Second argument is an integer array B containing departure time of booking.
Third argument is an integer C denoting the count of rooms.



Output Format
Return True if there are enough rooms for N bookings else return False.
Return 0/1 for C programs.



Example Input
Input 1:

 A = [1, 3, 5]
 B = [2, 6, 8]
 C = 1


Example Output
Output 1:

 0


Example Explanation
Explanation 1:

 At day = 5, there are 2 guests in the hotel. But I have only one room.

*/
bool comparator(pair<int,int>& p1,pair<int,int>& p2)
{
    return ((p1.first<p2.first) || (p1.first==p2.first && p1.second<=p2.second));
}
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    priority_queue<int,vector<int>,greater<int>>q1;
    vector<pair<int,int>>vis;
    for(int i=0;i<arrive.size();i++)
    {
        vis.push_back({arrive[i],depart[i]});
    }
    sort(vis.begin(),vis.end(),comparator);
    for(int i=0;i<vis.size();i++)
    {
        if(vis[i].first==vis[i].second)
        continue;
        if(q1.size()<K)
        {
            q1.push(vis[i].second);
        }
        else if(q1.size()==K)
        {
            if(q1.top()>vis[i].first)
            return false;
            else if(q1.top()<=vis[i].first)
            {
                q1.pop();
                q1.push(vis[i].second);
            }
        }
    }
    return  true;
}




