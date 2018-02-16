#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int g[10000],f;
map <string,int> mp;
vector <int> v[10000];

void fun(int x,int p)
{
    for(int i=0;i<v[x].size() && f;i++)
    {
        g[x]=p;
        if(g[v[x][i]]==p)
            {f=0;return;}
        fun(v[x][i],p);
    }
    v[x].clear();
}

int main()
{
    int t,m,n;
    string a,b;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        for(int j=1;j<10000;j++)
            g[j]=0;
        f=1;
        n=1;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            if(!mp[a])
                mp[a]=n++;
            if(!mp[b])
                mp[b]=n++;
            v[mp[a]].push_back(mp[b]);
        }
        for(int i=1;i<10000;i++)
        {
            if(v[i].size())
                fun(i,i);
            if(!f)
                break;
        }
        cout<<"Case "<<k+1<<": ";
        if(f)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        mp.clear();
        for(int i=1;i<10000;i++)
        v[i].clear();
    }
    return 0;
}
