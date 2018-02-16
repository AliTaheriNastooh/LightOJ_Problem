#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector <int> v[20001];
int y[2],p=0;

void fun(int x)
{
    int k,f=1;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i])
        {
            k=v[x][i];
            v[x][i]=0;
            f=1;
            for(int j=0;j<v[k].size();j++)
                if(v[k][j]==0)
                    {f=0;break;}
            for(int j=0;j<v[k].size();j++)
                if(v[k][j]==x)
                    {v[k][j]=0;break;}
            if(f)
                y[p]++;
            p = (p==0) ? 1 : 0;
            fun(k);
        }
    p = (p==0) ? 1 : 0;
    v[x].clear();
}

int main()
{
    int t,n,m=0;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i=1;i<20001;i++)
        {
            if(v[i].size())
            {
                y[0]=1;y[1]=0;p=1;
                fun(i);
                m+=max(y[0],y[1]);
            }
        }
        cout<<"Case "<<k+1<<": "<<m<<endl;
        m=0;
    }
    return 0;
}
