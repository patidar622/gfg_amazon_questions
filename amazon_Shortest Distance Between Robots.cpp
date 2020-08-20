class Solution{
    
public:

long closestPair(vector<pair<int,int>> points){
// 0<=x[i],y[i]<10^9    
    int n=points.size();
    if(n<2)  return 0;
 
    int N=0;
    long ans=LONG_MAX;
    unordered_set<string> myset;
    for(int i=0;i<n;i++){// get rid of duplicate points in the input
        string h=to_string(points[i].first)+" "+to_string(points[i].second);
        if(myset.count(h)>0)  continue;
        points[N++]=points[i];
        myset.emplace(h);
    }
    points.resize(N);
    if(N<2)  return 0;
    
    int e;
    for(e=29;e>=0;e--)// 2^29<1000000000<2^30
        if(!search(points,e,ans,false))break;
    
    search(points,e+1,ans,true);
    if(e+2<30)  search(points,e+2,ans,true);
    return ans;
}

bool search(vector<pair<int,int>>& points,int e,long& ans,bool checkpairs){
    
     int n=points.size();
     unordered_map<long,vector<int>> S;
        
     bool found=false;
     for(int i=0;i<n;i++){
         long hx=points[i].first>>e;
         long hy=points[i].second>>e;
            
         for(long gx=max(0LL,hx-1LL);gx<=hx+1LL;gx++)
             for(long gy=max(0LL,hy-1LL);gy<=hy+1LL;gy++){
                 long val=(gx<<30)+gy;
                 if(S.count(val)){
                     found=true;
                     if(!checkpairs)return true;
        
                     for(int j:S[val]){
                         int dx=points[i].first-points[j].first;
                         int dy=points[i].second-points[j].second;
                         long square_dist=(long)dx*dx+(long)dy*dy;
                         ans=min(ans,square_dist);
                     }
                 }
             }
        S[(hx<<30)+hy].push_back(i);
    }
    if(checkpairs)  assert(found);//safe check
    
    return found;
}};

int main(void){
    
    Solution *s=new Solution;
    
    cout<<s->closestPair({{0,0},{1,1},{2,4}})<<endl;    
    cout<<s->closestPair({{25,29},{32,30},{25,29}})<<endl;//duplicate points not counted
    cout<<s->closestPair({{92,52},{46,74},{96,91},{89,68},{69,73},{46,15},{6,28},{59,36},{28,3},{19,92}})<<endl;// random example with 10 points
    cout<<s->closestPair({{49,57},{68,43},{95,6},{74,57},{68,66},{65,2},{4,45},{1,73},{18,73},{14,34}})<<endl;// another random example
    
    return 0;
}
// output: 2 50 265 117
