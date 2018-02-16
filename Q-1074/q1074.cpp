#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


int arr[202];
vector<pair<int,int> > g;
const int ms=1<<25;
int dis[202];
int belman(int st,int v){
    memset(dis,ms,sizeof(dis));
    dis[st]=0;
    bool cycle=false;
    for(int i=0;i<v-1;i++){
      for(int j=0;j<g.size();j++){
        int u=g[j].first;
        int v=g[j].second;
        if(dis[u]!=ms && dis[v]>dis[u]+(arr[v]-arr[u])){
          if(i==v-1){
            dis[v]=ms;
          }else{
            dis[v]=dis[u]+(arr[v]-arr[u]);
          }
        }
      }
    }
}

int main() {
   int T;cin>>T;
   for(int j=0;j<T;j++){
       memset(arr,-1, sizeof(arr));
       // for(int i=0;i<202;i++){
       //     g[i].clear();
       // }
       g.clear();
       int n;cin>>n;
       for(int i=1;i<=n;i++){
           cin>>arr[i];
       }
       int m;cin>>m;
       for(int i=0;i<m;i++){
           int u;cin>>u;
           int v;cin>>v;
           g.push_back(make_pair(u,v));
       }
       int q;cin>>q;
       belman(1,n);
       cout<<"Case "<<j+1<<":\n";
       for(int i=0;i<q;i++){
          int tmp;cin>>tmp;
          if(dis[tmp]==ms || dis[tmp]<3){
            cout<<"?"<<endl;
          }else{
            cout<<dis[tmp]<<endl;
          }
       }
   }

    return 0;
}