#include <iostream>
#include <vector>

using namespace std;
const int mx=100000;
int main() {
    int T;cin>>T;
    for(int t=0;t<T;t++){
        int n;cin>>n;
        int m;cin>>m;
        int arr[105][105];
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                arr[i][j]=mx;
            }
        }
        for(int i=1;i<=n;i++){
            arr[i][i]=0;
        }
        for(int i=0;i<m;i++){
            int u;cin>>u;
            int v;cin>>v;
            int w;cin>>w;
            arr[u][v]=min(w,arr[u][v]);
            arr[v][u]=min(w,arr[v][u]);
        }
        for(int i=1;i<=n;i++){
            for(int s=1;s<=n;s++){
                for(int d=1;d<=n;d++){
                    if(arr[s][d]>arr[s][i]+arr[i][d]){
                        arr[s][d]=arr[s][i]+arr[i][d];
                    }
                }
            }
        }
        cout<<"Case "<<t+1<<": ";
        int res=min(arr[1][n],arr[n][1]);
        if(res==mx){
            cout<<"Impossible"<<endl;
        }else{
            cout<<res<<endl;
        }
    }

    return 0;
}