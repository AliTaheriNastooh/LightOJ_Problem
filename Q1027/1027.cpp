#include <iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
#define N 1000
int* a;
int* b;
int b2,b1;
void f(int first,int sec){
    a=new int[N];
    b=new int[N];
for(int i=0 ; i< N ; i++){
    a[i]=i;
}
int j=0;
for(int i=2 ; i<N ;i++){
    if(a[i]){
        b[j++]=a[i];
        for(int k=2;k*i<N ;k++){
            a[k*i]=0;
        }
    }
}
    for(int i=0 ;b[i]<first && b[i]<=sec;){
        if(first%b[i]==0 && sec%b[i]==0){
            first/=b[i];
            sec/=b[i];

        }
        else{
            i++;
        }
    }
    b2=first;
    b1=sec;
}
int main()
{
    int n,tmp,n1;
    long long int s;
    int counte=0;
    cin>>n1;
    for(int j=0 ; j<n1 ; j++){
    counte=0;
    s=0;
    cin>>n;
    for(int i=0 ;i<n ; i++){

        cin>>tmp;
        if(tmp<0)
        {

            s+=tmp*-1;
        }
        else{
            counte++;
            s+=tmp;
        }
        }
        if(counte ==0){
            cout<<"Case "<<j+1<<": "<<"inf"<<endl;
            continue;
        }
        if(counte==1){
            cout<<"Case "<<j+1<<": "<<s<<'/'<<counte<<endl;
            continue;
        }
        f(s,counte);
        cout<<"Case "<<j+1<<": "<<b2<<'/'<<b1<<endl;
    }

    return 0;
}
