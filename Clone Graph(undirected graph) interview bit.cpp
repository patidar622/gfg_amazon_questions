/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
#define un UndirectedGraphNode 
map<un*,un*>m1;
un* find_solution(un* node)
{
    if(node==NULL)
    return NULL;
    
    un* n1=new UndirectedGraphNode(node->label);
     m1[node]=n1;
    for(un* i:node->neighbors)
    {
        if(m1.find(i)==m1.end())
          n1->neighbors.push_back(find_solution(i));
          else
        n1->neighbors.push_back(m1[i]);
    }
  
    return n1;
}
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    m1.clear();
    un* n1=find_solution(node);
return n1;
}

