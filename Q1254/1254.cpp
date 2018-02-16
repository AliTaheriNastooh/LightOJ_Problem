#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int inf=1<<26;

bool cmp(pair< pair<int ,int> ,int >  a, pair< pair<int ,int> ,int > b){
    return 1;
}

int arr[102];
vector<int> g[102],w[102];

int dikstra(int s,int t,int cap){
    int dis[102][102];
    for(int i=0;i<102;i++){
        for(int j=0;j<102;j++){
            dis[i][j]=inf;
        }
    }
    dis[s][0]=0;
    priority_queue<pair< pair<int ,int> ,int > ,vector< pair< pair<int ,int> ,int >  > , greater< pair< pair<int ,int> ,int >  > > pq;
    pq.push(make_pair(make_pair(0,0),s));
    while(!pq.empty()){
        int sum=pq.top().first.first;
        int bak=pq.top().first.second;
        int u=pq.top().second;
        pq.pop();
        if(u==t)return sum;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            int weight=w[u][i];
            if(weight>cap)continue;
            if( bak>=weight && sum<dis[v][bak-weight]){
                dis[v][bak-weight]=sum;
                pq.push(make_pair(make_pair(sum,bak-weight),v));
            }

        }
        if(bak<cap){
            // dis[u][bak+1]=dis[u][bak]+arr[u];
            pq.push(make_pair(make_pair(sum+arr[u],bak+1),u));
        }
    }
    return inf;
}


int main(){
    int T;cin>>T;
    for(int j=0;j<T;j++){
        int n;cin>>n;
        int m;cin>>m;
        for(int i=0;i<102;i++) {arr[i]=0; g[i].clear(); w[i].clear();}
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<m;i++){
            int a;cin>>a;
            int b;cin>>b;
            int c;cin>>c;
            g[a].push_back(b);
            w[a].push_back(c);
            g[b].push_back(a);
            w[b].push_back(c);
        }
        cout<<"Case "<<j+1<<":\n";
        int q;cin>>q;
        for(int i=0;i<q;i++){
            int a;cin>>a;
            int b;cin>>b;
            int c;cin>>c;
            int x=dikstra(b,c,a);
            if(x==inf)
                cout<<"impossible\n";
            else
                cout<<x<<endl;
        }
    }
    return 0;
}