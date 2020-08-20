#include <bits/stdc++.h>
using namespace std;

vector<int> Turnstile(int n,vector<int> dir ,vector<int> T){
	deque< pair<int,int> > in,out;
	std::vector<int> res(n);
	for(int i=0;i<n;i++){
		if(dir[i]){
			out.push_back({T[i],i});
		}
		else{
			in.push_back({T[i],i});
		}
	}
	sort(in.begin(), in.end());
	sort(out.begin(), out.end());
	int lastop=-1;		                                  //(last-operation in or out)
	int time=0;bool op;                                  //op==1 next one goes in else next one exits
	while(!in.empty() || !out.empty()){
			if(!in.empty() && !out.empty()){
				in.front().first=max(time,in.front().first);
				out.front().first=max(time,out.front().first);
				if(in.front().first < out.front().first)op=0;
				else if(out.front().first < in.front().first)op=1;
				else{
					if(time == in.front().first && lastop!= -1){             //used in prev second
						if(lastop==0) op=0;
						else op=1;
					}
					else{
						op=1;
					}
				}
				if(op==0){
					time=res[in.front().second]=max(time,in.front().first);
					in.pop_front();lastop=0;time++;
					continue;
				}
				else{
					time=res[out.front().second]=max(time,out.front().first);
					out.pop_front();lastop=1;time++;
					continue;
				}
			}
			else{
				while(!in.empty()){
					time=res[in.front().second]=max(time,in.front().first);
					in.pop_front();time++;
				}
				while(!out.empty()){
					time=res[out.front().second]=max(time,out.front().first);
					out.pop_front();time++;
				}
			}
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	vector<int> dir(n);
	vector<int> T(n);
	for(int i=0;i<n;i++){
		cin>>T[i];
	}
	for(int i=0;i<n;i++){
		cin>>dir[i];
	}
	vector<int> res=Turnstile(n,dir,T);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<' ';
	}
}
