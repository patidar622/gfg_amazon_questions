class Solution {
public:
    map<int,vector<int>>m1;
    bool is_bipartite(int i,vector<int>& vis)
    {
        int color=1;
        queue<int>q1;
        q1.push(i);
        vis[i]=1;
        while(!q1.empty())
        {
         int i1=q1.front();
            q1.pop();
            for(int j=0;j<m1[i1].size();j++)
            {
                if(vis[m1[i1][j]]==vis[i1])
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
    bool possibleBipartition(int N, vector<vector<int>>& dis) {
        m1.clear();
        for(int i=0;i<dis.size();i++)
        {
            m1[dis[i][0]].push_back(dis[i][1]);
            m1[dis[i][1]].push_back(dis[i][0]);
        }
        vector<int>vis(N+1,-1);
        
        for(int i=1;i<=N;i++)
        {
            if(vis[i]==-1)
            {
                if(!is_bipartite(i,vis))
                    return false;
            }
        }
        return true;
    }
};
