#include <iostream>
#include <cstring>

using namespace std;

long long int h[65][65];
string s1;
long long int rec (int first ,int end){

    if(first> end)return 0;
    if(first==end){
        return  1;
    }
    if(h[first][end] != -1)return h[first][end];
    long long sum=0;
    if(s1[first]==s1[end]){
        sum+= 1+ rec(first+1,end)+rec(first,end-1);
    }else{
        sum += rec(first+1,end)+rec(first,end-1)-rec(first+1,end-1);
    }
    return h[first][end]=sum;
}

int main() {
    int t;cin >>t;
    for(int i=0;i<t;i++){
        cin>>s1;
        memset(h,-1,sizeof(h));
        cout<<"Case "<<i+1<<": "<<rec(0,s1.size()-1) <<endl;
    }

    return 0;
}