#include <iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
long long int a,b,c;
long long int f(long long int t){

return t*(b-(t*a));
}
int main()
{
    int n;

    cin>>n;
    for(int i=0 ; i<n ; i++){
        cin>>a>>b;
        if(a==0){
            cout<<"Case "<<i+1<<": "<<0<<endl;
            continue;
        }
        if(f(b/(2*a))>=f((b/(2*a))+1))
            cout<<"Case "<<i+1<<": "<<b/(2*a)<<endl;
        else
            cout<<"Case "<<i+1<<": "<<b/(2*a)+1<<endl;
    }
    return 0;
}
