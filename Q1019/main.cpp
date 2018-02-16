#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

using namespace std;
#define MAX1 102
#define inf 1<<7
vector<int > arr[MAX1];
vector<int> weight[MAX1];



int dikstra(int s,int t){
    int visited[MAX1];
    int color1[MAX1];
    int  dis[MAX1];
    priority_queue<pair<int ,int> > q;
    memset(visited,0, sizeof(visited));
    memset(color1,0, sizeof(color1));
    memset(dis,inf,sizeof(dis));
    dis[s]=0;
    color1[s]=1;
    q.push(make_pair(0,s));
    while(!q.empty()){
        pair<int,int> u=q.top();
        q.pop();
        if(color1[u.second]==2)continue;
        if(u.second==t)return dis[u.second];
        color1[u.second]=2;
        for(int i=0;i<arr[u.second].size();i++){
            int v=arr[u.second][i];
            if(color1[v]==0){
                color1[v]=1;
                dis[v]=dis[u.second]+weight[u.second][i];
                q.push(make_pair(dis[u.second]+weight[u.second][i],v));
            }
            if(color1[v]==1 && dis[v]>dis[u.second]+weight[u.second][i]){
                // q.push(make_pair(v,u.second+weight[u.second][i]));
                dis[v]=dis[u.second]+weight[u.second][i];
            }
        }
    }
    return inf;
}
int main() {

    int T;cin>>T;
    for(int t=0;t<T;t++){
        int n;cin>>n;
        int m;cin>>m;
        map<pair<int,int>,int> mp;
        for(int i=0;i<MAX1;i++){
            arr[i].clear();
            weight[i].clear();
        }
        for(int i=0;i<m;i++){
            int u;cin>>u;
            int v;cin>>v;

            int w;cin>>w;
            arr[u].push_back(v);
            int res=inf;
            auto it=mp.find(make_pair(u,v));
            if(it!=mp.end()){
                res=it->second;
            }
            mp[make_pair(u,v)]=min(res,w);
            weight[u].push_back(min(res,w));
        }
        cout<<"Case "<<t+1<<": ";
        int res=dikstra(1,n);
        if(res==inf){
            cout<<"Impossible"<<endl;
        }else{
            cout<<res<<endl;
        }

    }
    return 0;
}