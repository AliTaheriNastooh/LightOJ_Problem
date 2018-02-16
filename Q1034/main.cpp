#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MAX1 10004
int res[MAX1];
int N;
vector<int > arr[MAX1];
int  visited[MAX1];
int counter=0;
void dfs1(int s){
    //cout<<" first "<<s<<endl;
    visited[s]=1;
    for(int i=0;i<arr[s].size();i++){
        if(!visited[arr[s][i]]){
            dfs1(arr[s][i]);
        }
    }
    //cout<<s<< " - s  : coumter- "<<counter<<endl;
    res[counter--]=s;
}
void dfs2(int s){
    visited[s]=1;
    for(int i=0;i<arr[s].size();i++){
        if(!visited[arr[s][i]]){
            dfs2(arr[s][i]);
        }
    }
}
int main() {
    int T;cin>>T;
    for(int t=0;t<T;t++){
        cin>>N;
        int n;cin>>n;
        counter=N-1;
        for(int i=0;i<MAX1;i++){
            arr[i].clear();
        }
        for(int i=0;i<n;i++){
            int a;cin>>a;
            int b;cin>>b;
            arr[a].push_back(b);
        }
        memset(visited,0,sizeof(visited));
        memset(res,-1,sizeof(res));
        for(int i=1;i<=N;i++){
            if(!visited[i]){
                dfs1(i);
            }
        }
        int sum=0;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<N;i++){
            if(!visited[res[i]]){
                dfs2(res[i]);
                sum++;
            }

        }
        cout<<"Case "<<t+1<<": "<<sum<<endl;
    }

    return 0;
}