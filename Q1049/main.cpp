#include <iostream>
#include <vector>
#include <cstring>
#include<climits>
using namespace std;
 bool visited[104];
vector<pair<int ,int > > arr[104];
int counter=0;
int N;
int dfs(int s){
    //cout<<"first s:"<<s<<endl;
    visited[s]=true;
    counter++;
    int best=INT_MAX;
    for(int i=0;i<arr[s].size();i++){
        if(! visited[arr[s][i].first]){
            int tmp=dfs(arr[s][i].first)+arr[s][i].second;
            //cout<<"s :"<<s<<" aa : "<<arr[s][i].first<<" tmp : "<<tmp<<" c:"<<arr[s][i].second<<endl;
            if(tmp<best){
                best=tmp;
            }
        }else{
            if(counter==N && arr[s][i].first==1){
               // cout<<" my "<<arr[s][i].second<<endl;
                best=arr[s][i].second;
            }
        }
    }
//    if(best==INT32_MAX){
//        best=0;
//    }
    visited[s]=false;
    counter--;
    return best;
}


int main() {
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        memset(visited,false, sizeof(visited));
        counter=0;
        N=n;
        for(int j=0;j<104;j++){
            arr[j].clear();
        }
        for(int j=0;j<n;j++){
            int tmp1,tmp2,tmp3;
            cin>>tmp1>>tmp2>>tmp3;
            arr[tmp1].push_back(make_pair(tmp2,0));
            arr[tmp2].push_back(make_pair(tmp1,tmp3));

        }
        cout<<"Case "<<i+1<<": "<<dfs(1)<<endl;
    }

    return 0;
}