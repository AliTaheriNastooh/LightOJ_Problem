#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int K,W,N;
vector<pair<int ,int > > arr,acc;
int comp(const pair<int ,int > &a,const pair<int,int> &b){
    return a.second<b.second;
}
int h[101][101];
int rec(int num,int index){
    if(num==K || index==arr.size()){
        return 0;
    }
    if(h[num][index]!=-1){
        return h[num][index];
    }
    int max1=-1;
    for(int i=index;i<arr.size();i++){
        max1=max(max1,rec(num+1,acc[i].second)+acc[i].first);
    }
    return h[num][index]=max1;
}

int main() {
    int n;cin>>n;
    for(int i=0 ;i<n;i++){
        cin>>N>>W>>K;
        vector< pair <  int,int > > tmp;
        for(int j=0;j<N ;j++){
            int x,y;cin>>x>>y;
            tmp.push_back(make_pair(x,y));
        }
        sort(tmp.begin(),tmp.end(),comp);
        int counter=1;
        for(int j=1;j<N;j++){
            if(tmp[j].second==tmp[j-1].second){
                counter++;
            }else{
                //cout<<counter<<endl;
                arr.push_back(make_pair(tmp[j-1].second,counter));
                counter=1;
            }
        }
        //cout<<counter<<endl;
        arr.push_back(make_pair(tmp[tmp.size()-1].second,counter));
        counter=arr[0].second;
        int j=1,index=0;
        while(j!=arr.size()){
            if(arr[j].first - arr[index].first <= W){
                counter+=arr[j].second;
                j++;
            }else{
                acc.push_back(make_pair(counter,j));
                counter-=arr[index].second;
                index++;
            }
        }
        for(int k=index;k<arr.size();k++){
            acc.push_back(make_pair(counter,arr.size()));
            counter-=arr[k].second;
        }
        for(int j1=0;j1<101;j1++){
            for(int k=0;k<101;k++){
                h[j1][k]=-1;
            }
        }
        cout<<"Case "<<i+1<<": "<<rec(0,0)<<endl;
        arr.clear();
        acc.clear();
    }
   return 0;
}