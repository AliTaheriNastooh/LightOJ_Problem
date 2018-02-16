
#include <iostream>
#include <vector>
#include <cstring>

#define mymax 666
using namespace std;

int his[20][20];

/*
 *
 solution one  ----> time limit
*/
vector <pair<int ,int > > arr;
int end1;
int h[(1<<20)];
int rec(int bm){
    //cout<<"bit"<<bm<<endl;
    if(bm==end1){
        return 0;
    }
    if(h[bm]!= -1){
        return h[bm];
    }
    if(__builtin_popcount(bm) == (arr.size() - 1)) {
        return h[bm] = 1;
    }


    int min1=mymax;
    int i;
    for(i=0;(bm>>i)&1;i++);

    for(int j=0;j<arr.size();j++)if(((bm>>j)& 1)==0 && (i!= j)){
            //cout<<"min1 : "<<min1<<"  "<<his[i][j]<<endl;
            min1=min(min1,rec(his[i][j])+1);

        }
    return h[bm]=min1;
}



bool coolin(int i,int j,int k){
    if(((arr[i].first - arr[j].first)*(arr[k].second - arr[j].second) ) -
            ((arr[i].second - arr[j].second) *(arr[k].first - arr[j].first)) ==0){
        return true;
    }
    return false;
}
void set(){
    memset(his,0, sizeof(his));
    for(int i=0;i<arr.size();i++)
        for(int j=0;j< arr.size();j++){
            for(int k=0;k<arr.size();k++)

                if( (i!=j) && coolin(i,j,k) ){
                    his[i][j] |= (1<<k);
                }

           // cout<<" his "<<i<<" "<<j<<"  :"<<his[i][j]<<endl;
        }

}

int main() {
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        arr.clear();
        for(int j=0;j<n;j++){
            int x;cin>>x;
            int y;cin>>y;
            arr.push_back(make_pair(x,y));
        }
        memset(h,-1, sizeof(h));
        end1=(1<<n)-1;
        set();
        cout<<"Case "<<i+1<<": "<<rec(0)<<endl;
    }

    return 0;
}
