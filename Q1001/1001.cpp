#include <iostream>
#include<map>
using namespace std;

int main()
{
    int n,m;
    int mp[50]={0};
    cin>>n;
    for(int i=0 ; i< n ; i++){
        cin>>m;
        if(m>10){
                cout<<m-10<<" "<<10<<endl;

        }else{
            cout<<0<<" "<< m<<endl;

        }
    }
    return 0;
}
