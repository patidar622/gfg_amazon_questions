/*
Problem Description

You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

Your target is to go from top left corner to the bottom right corner of the matrix.

But there are some restrictions while moving along the matrix:

If you follow what is written in the cell then you can move freely.
But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.



Problem Constraints
1 <= A,B <= 103
C[i][j] can be either U,R,L or D.


Input Format
First Argument represents a integer A (number of rows).
Second Argument represents a integer B (number of columns).
Third Argument represents a string array C which contains A strings each of length B.


Output Format
Return an integer denoting the minimum cost to travel from top-left corner to bottom-right corner.



Example Input
Input:1

 A = 3
 B = 3
 C = ["RRR","DDD","UUU"]
Input:2

 A = 1
 B = 4
 C = ["LLLL"]


Example Output
Output-1 :

 1
Output-2 :

 3


Example Explanation*
Explanation for Input-1:

 Matrix looks like: RRR
                    DDD
                    UUU
 We go right two times and down two times.
 So from top-right cell we are going down though right is given so this incurs a cost of 1.
Explanation for Input-2:

 Matrix looks like: LLLL
 We go right three times.
 
 
 
 *** solution approach ***
 As told in hint that you just to need to find out the shortest path between top-left corner and bottom-right corner.

Thinking of shortest path algorithms the first thing that comes to our mind is Dijsktra Algorithm with time complexity of O(V+ElogV) which is good but can we make it better?

The answer is yes we can apply 0-1 BFS here which is nothing just a BFS on weighted graph where each edge has binary weights.

So what does the 0-1 BFS algo says:
Read it from here : Click here

So, till here you are clear about the concept and implementation of 0-1 BFS.

Algorithm:

1) Start with cell (0,0) push it into the doubly-ended queue and also make it distance as 0.
2) Pop the front node from the queue.
3) You can go to four directions from the popped node so if you go to a direction that is written on the cell then mark dist[neighbour]=dist[current]+1 else dist[neighbour]=dist[curr]
4) If direction in which you move is not same as the direction written on the cell so this implies you have to incur a cost of 1 so push it to the back of queue else push it to the front of the queue.
5) Repeat steps 2-4
*/
#define ti tuple<int,int,int>
int Solution::solve(int A, int B, vector<string> &C) {
vector<vector<bool>>dp(A,vector<bool>(B,false));
deque<ti>q1;
q1.push_front({0,0,0});
while(!q1.empty())
{
    auto [cost,i,j]=q1.front();q1.pop_front();
    if(i==A-1 && j==B-1)
    return cost;
    dp[i][j]=true;
    if(i-1>=0 && !dp[i-1][j])
    {
        if(C[i][j]=='U')
        q1.push_front({cost,i-1,j});
        else
        q1.push_back({cost+1,i-1,j});
    }
    if(i+1<A && !dp[i+1][j])
    {
        if(C[i][j]=='D')
        q1.push_front({cost,i+1,j});
        else
        q1.push_back({cost+1,i+1,j});
    }
    if(j-1>=0 && !dp[i][j-1])
    {
        if(C[i][j]=='L')
        q1.push_front({cost,i,j-1});
        else
        q1.push_back({cost+1,i,j-1});
    }
    if(j+1<B && !dp[i][j+1])
    {
        if(C[i][j]=='R')
        q1.push_front({cost,i,j+1});
        else
        q1.push_back({cost+1,i,j+1});
    }
}
return -1;
}

