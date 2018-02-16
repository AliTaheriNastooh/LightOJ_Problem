#include <iostream>


using namespace std;

int base1 ,k;
string num;
long long int arr[1<<16][21];
int end1;

int getnum(char c){
    if(c >='0' && c<='9'){
        return c-'0';
    }
    return 10+(c-'A');
}

long long int rec(int bm,int rem){
    if(bm==end1){
        if(rem==0){
            return 1;
        }
        return 0;
    }
    if(arr[bm][rem]!=-1){
        return arr[bm][rem];
    }
    long long ans=0;
    for(int i=0;i<base1;i++){
        if((bm & (1<<i)) == 0){
            ans+=rec((bm | 1<<i),((rem*base1)+getnum(num[i]))%k);
        }
    }
    return arr[bm][rem]=ans;
}

int main() {
    int t;cin>>t;
    for(int i=0;i<t;i++){
        cin>>base1>>k;
        cin>>num;
        end1=(1<<num.size())-1;
        for(int j=0;j<(1<<16);j++){
            for(int k=0;k<20;k++){
                arr[j][k]=-1;
            }
        }
        cout<<"Case "<<i+1<<": "<<rec(0,0)<<endl;
    }
    return 0;
}