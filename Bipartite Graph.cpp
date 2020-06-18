map<int,vector<int>>m1;
bool is_bipartite(int i,vector<int>& vis)
{
    int color=1;
    queue<int>q1;
    vis[i]=color;
    q1.push(i);
    while(!q1.empty())
    {
        int i1=q1.front();q1.pop();
        for(int j=0;j<m1[i1].size();j++)
        {
            if(vis[i1]==vis[m1[i1][j]])
            return false;
            
            if(vis[m1[i1][j]]==-1)
            {
                int c1=1-vis[i1];
                vis[m1[i1][j]]=c1;
                q1.push(m1[i1][j]);
            }
        }
    }
    return true;
}
bool isBipartite(int G[][MAX],int V)
{
     m1.clear();
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++){
        if(G[i][j]==1)
        m1[i].push_back(j);
        }
    }
    vector<int>vis(V,-1);
    for(int i=0;i<V;i++)
    {
        if(vis[i]==-1)
        {
            if(!is_bipartite(i,vis))
            return false;
        }
    }
    return true;
    
    
}
