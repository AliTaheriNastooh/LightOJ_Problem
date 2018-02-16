#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector < pair<int , int > > arr;
vector <int > k1;
int n,m;
int dir1[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
priority_queue<pair< int , pair<int ,int > > ,vector<pair< int , pair<int ,int > >>,greater<pair< int , pair<int ,int > >> > pq;
void rec(int x,int y,int k,int count){
    if(k==0)return;
    for(int i=0;i<8;i++){
        int tx1=x+dir1[i][0];
        int tx2=y+dir1[i][1];
        if(tx1 >= m || tx1<0 || tx2>=n || tx2<0)
            continue;
        pq.push(make_pair(count,make_pair(tx1,tx2)));
        rec(tx1,tx2,k-1,count);
    }
}
int bfs1(int x1,int y1,int x2,int y2,int k2){
     map <pair<int , int > , bool> um1;
    pq.push(make_pair(0,make_pair(x1,y1)));
    while(!pq.empty()){
        pair <int , pair <int ,int > > tmp=pq.top();
        pq.pop();

        if(tmp.second == make_pair(x2,y2))return tmp.first;
        if(um1[tmp.second]==1){
            continue;
        }
      //  cout<<"tmp x:"<<tmp.second.first<<" tmp y:"<<tmp.second.second<<endl;
        um1[tmp.second]=1;
        rec(tmp.second.first,tmp.second.second,k2,tmp.first+1);
    }
    return -1;
}

int main() {
    int t;cin>>t;
    for(int i=0;i<t;i++){
        cin>>m>>n;
        arr.clear();
        k1.clear();
        while(!pq.empty())pq.pop();
        for(int j=0;j<m;j++){
            string s;cin>>s;
            for(int k=0;k<n;k++){
                if(s[k] != '.'){
                    arr.push_back(make_pair(j,k));
                    //cout<<"j: "<<j<<" K:"<<k<<" : "<<s[k]<<endl;
                    k1.push_back(s[k]-'0');
                }
            }

        }
        int min1=INT32_MAX;
        for(int i1=0;i1<m;i1++){
            for(int j1=0;j1<n;j1++){
                int sum=0;
                for(int k2=0;k2<arr.size();k2++){
                    int test=bfs1(arr[k2].first,arr[k2].second,i1,j1,k1[k2]);
                    //cout<<"test:"<<test<<" i1:"<<i1<<" j1:"<<j1<<" x:"<<arr[k2].first<<" y:"<<arr[k2].second<<endl;
                    if(test!=-1){
                        sum+=test;
                    }else{
                        sum=INT32_MAX;
                        break;
                    }
                }
                min1=min(sum,min1);
            }
        }
        if(min1==INT32_MAX)min1=-1;
        cout<<"case "<<i+1<<": "<<min1<<endl;
    }

    return 0;
}