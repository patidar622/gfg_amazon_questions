/*

There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:



Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
 

Constraints:

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
There are no repeated connections.


*/
class Solution {
public:
    vector<vector<int> >graph,result;
    vector<bool> visited;
    vector<int> low,vis;
    int count=0;
    void dfs(int node,int parent)
    {
        low[node]=vis[node]=count++;
        visited[node]=true;
        
        for(auto i1:graph[node])
        {
            if(i1==parent)
            continue;
            
            if(!visited[i1])
            {
                dfs(i1,node);
                low[node]=min(low[node],low[i1]);
                if(vis[node]<low[i1])
                {
                    result.push_back({node,i1});
                }
            }
            else
                low[node]=min(low[node],vis[i1]);
        }   
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        count=0;
        graph.clear();
        result.clear();
        visited.clear();
        low.clear();
        vis.clear();
        graph.resize(n);
        low.resize(n,0);
        vis.resize(n,0);
        visited.resize(n,false);
        for(int i=0;i<con.size();i++)
        {
            graph[con[i][0]].push_back(con[i][1]);
            graph[con[i][1]].push_back(con[i][0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,i);
            }
        }
        return result;
    }
};
