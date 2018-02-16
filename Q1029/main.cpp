#include <iostream>
#include <vector>
#include <cstdlib>
#include <search.h>
#include <algorithm>

using namespace std;

struct subset{
    int rank;
    int parent;
};
struct edge{
    int u;
    int v;
    int w;
};
vector<edge >e;
vector<subset> sub;
int mycomp(edge a,edge b){
    return a.w>b.w;
}
int mycomp2(edge a,edge b){
    return a.w<b.w;
}
int myfind(int u){
    if(sub[u].parent !=u){
        return sub[u].parent=myfind(sub[u].parent);
    }
    return sub[u].parent;
}
void myunion(int u,int v){
    int x=myfind(u);
    int y=myfind(v);
    if(sub[x].rank>sub[y].rank){
        sub[y].parent=x;
    }else{
        if(sub[x].rank<sub[y].rank){
            sub[x].parent=y;
        }else{
            sub[x].parent=y;
            sub[x].rank++;
        }
    }
}
int mst1(int n){
    for(int i=0;i<=n;i++){
        subset tmp;
        tmp.rank=0;
        tmp.parent=i;
        sub.push_back(tmp);
    }
    sort(e.begin(),e.end(),mycomp2);
    //cout<<e[0].w<<" test "<<endl;
    int i=0;
    int sum=0;
    int counter=0;
    while(counter!=n){
        int x=myfind(e[i].u);
        int y=myfind(e[i].v);
        if(x!=y){
            myunion(x,y);
            sum+=e[i].w;
            counter++;
        }
        i++;
    }

    sort(e.begin(),e.end(),mycomp);
    i=0;
    int sum2=0;
    counter=0;
   // cout<<sum<<" test2"<<endl;
    sub.clear();
    for(int i1=0;i1<=n;i1++){
        subset tmp;
        tmp.rank=0;
        tmp.parent=i1;
        sub.push_back(tmp);
    }
    while(counter!=n){
        int x=myfind(e[i].u);
        int y=myfind(e[i].v);
        if(x!=y){
            myunion(x,y);
            sum2+=e[i].w;
            counter++;
        }
        i++;
    }
    return sum+sum2;
}

int main() {
    int T;cin>>T;
    for(int i=0;i<T;i++){
        int n;cin>>n;
        e.clear();
        sub.clear();
        while(true){
            int u;cin>>u;
            int v;cin>>v;
            int w;cin>>w;
            if(!u && !v && !w){
                break;
            }
            edge tmp;
            tmp.u=u;
            tmp.v=v;
            tmp.w=w;
            e.push_back(tmp);
        }
        long long int res=mst1(n);
        cout<<"Case "<<i+1<<": ";
        if(res%2==0){
            cout<<res/2<<endl;
        }else{
            cout<<res<<"/2"<<endl;
        }

    }


    return 0;
}