class pairstring{
public:
    string first;
    string second;
    
    pairstring(string first,string second){
        this->first=first;
        this->second=second;
    }
};

int dfs(map<string,set<string>>& graph,string s,string adj,unordered_set<string>& vis){
    vis.insert(adj);
    graph[s].insert(adj);
    int count=0;
    for(string& nbr:graph[s]){
        if(vis.count(nbr)==0){
            count+=dfs(graph,s,nbr,vis);
        }
    }
    return count+1;
}

vector<string> largestItemAssociation(vector<pairstring>& itemAssociation){
    map<string,set<string>> graph;
    int n=itemAssociation.size();
    for(int i=0;i<n;i++){
        graph[itemAssociation[i].first].insert(itemAssociation[i].second);
        graph[itemAssociation[i].second].insert(itemAssociation[i].first);
    }
    unordered_set<string> vis;
    int count=0,ans=0;
    string res="";
    for(auto& p:graph){
        if(vis.count(p.first)==0){
            count=dfs(graph,p.first,p.first,vis);
            if(count>ans){
                ans=count;
                res=p.first;
            }
        }
    }
    vector<string> ansaray;
    for(it=graph[res].begin(),it!=graph[res].end();it++){
         ansaray.push_back(*it);
    }
    return ansaray;
}
