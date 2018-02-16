#include <iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main()
{
    int n;
    long long int m,m2,m3;
    long double a,b;
    cin>>n;
    for(int i=0 ; i<n;i++){
        cin>>a;
        m2=(long long int)a;
        b=sqrt(a);

        m=(long long int)b;
        if(m*m!=m2)
            m++;
        if(m%2==0){
        m3=(m*m)-m2;
         if(m3>=m){
            cout<<"Case "<<i+1<<": "<<m3*-1+((2*m)-1)<<" "<<m<<endl;
         }
         else{

            cout<<"Case "<<i+1<<": "<<m<<" "<<m3+1<<endl;
         }
        }
        else{
         m3=(m*m)-m2;
         if(m3>=m){
            cout<<"Case "<<i+1<<": "<<m<<" "<<m3*-1+((2*m)-1)<<endl;
         }
         else{

            cout<<"Case "<<i+1<<": "<<m3+1<<" "<<m<<endl;
         }

        }

    }
    return 0;
}
