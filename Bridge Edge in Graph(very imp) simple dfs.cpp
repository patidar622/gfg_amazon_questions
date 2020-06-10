/*
Your Task:
You don't need to read input or print anything. 
Your task is to complete the function isBridge() which takes the graph g, number of vertices N and the two end vertices s and e of an edge as inputs and returns true if the given edge is a Bridge. Else, it returns false.

Expected Time Complexity: O(N + M).
Expected Auxiliary Space: O(N).
*/
void dfs(list<int> adj[],vector<bool>& visited,int s)
{
    visited[s]=true;
    list<int>::iterator i;
    for(i=adj[s].begin();i!=adj[s].end();i++)
    {
        if(!visited[*i])
        dfs(adj,visited,*i);
    }
}
bool isBridge(list<int> adj[], int V, int s, int e) {
        adj[s].remove(e);
        adj[e].remove(s);
        vector<bool>visited(V,false);
    dfs(adj,visited,s);
    if(!visited[e])
    return true;
    return false;
}
