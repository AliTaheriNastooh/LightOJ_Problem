#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
double h[105];
int n;
vector<int > arr;

double rec(int pos){
    if(pos >= n){
        return -1;
    }
    if(pos==n-1){
        return arr[n-1];
    }
    if(h[pos] != -1){
        return h[pos];
    }
    int cnt=0;
    double sum=0;
    for(int i=1;i<7;i++){

        double tmp=rec(pos+i);
        cout<<tmp<<"  ss "<<i<<endl;
        if(tmp != -1){

            cnt++;
            sum+=tmp;
        }
    }
    if(cnt) {
        sum = sum / cnt;
    }
    sum+=arr[pos];
    return h[pos]=sum;
}

int main() {
    int t;cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            int tmp;cin>>tmp;
            arr.push_back(tmp);
        }
        memset(h,-1,sizeof(h));
        cout<<"Case "<<i+1<<": "<<rec(0)<<endl;
    }
    return 0;
}