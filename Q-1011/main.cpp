#include <iostream>

using namespace std;
int arr[17][17];
int h[17][65539];
int N;
int rec(int n,int b){
    if(n==N){
        return 0;
    }
    if(h[n][b]!=-1)return h[n][b];
    int max1=-1;
    for(int i=0;i<N ;i++){
        if(!(b & 1<<i)){
            max1=max(max1,rec(n+1,(b | 1<<i))+arr[n][i]);
        }
    }
    return h[n][b]=max1;
}
int main() {
    int n;cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<17;j++){
            for(int k=0;k<65539;k++){
                h[j][k]=-1;
            }
        }
        cin>>N;
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                cin>>arr[j][k];
            }
        }
        cout<<"Case "<<i+1<<": "<< rec(0,0)<<endl;
    }

    return 0;
}