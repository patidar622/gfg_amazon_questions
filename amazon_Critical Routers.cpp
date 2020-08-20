#include<bits/stdc++.h>
using namespace std;

const int mxN=10e6;
vector<int>in(mxN),low(mxN),visited(mxN),res;
vector<vector<int>>adj(mxN);
int timer=0;
void dfs(int node,int par){
    visited[node]=1;
    in[node]=low[node]=timer++;
    int children=0;
    for(auto child:adj[node]){
        if(node==par)
            continue;
        else if(visited[child]){
            low[node]=min(low[node],in[child]);
        }
        else{
            dfs(child,node);
            if(low[child]>=in[node] and par!=-1){
                res.emplace_back(node);
            }
            low[node]=min(low[node],low[child]);
            children++;
        }
    }
    if(par==-1 and children>1)
        res.emplace_back(node);
}

int main(){
    int n;
    cin>>n;
    int edges;
    cin>>edges;
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(0,-1);
    cout<<"The articulation points are \n";
    for(auto vec:res){
        cout<<vec<<" ";
    }
}
