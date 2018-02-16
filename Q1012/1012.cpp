#include <iostream>
#include <vector>
using namespace std;

vector <int> v[401];
int g[401],m;

int fun(int x)
{
    for(int i=0;i<v[x].size();i++)
        if(g[v[x][i]])
        {
            g[v[x][i]]=0;
            m++;
            fun(v[x][i]);
        }
}

int main()
{
    int t,a,b,x;
    char arr[20][20];
    cin>>t;
    for(int k=0;k<t;k++)
    {
        m=0;
        for(int i=0;i<401;i++)
            g[i]=1;
        cin>>b>>a;
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='@')
                    x=i*b+j+1;
            }
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
            {
                if(arr[i][j]!='#')
                {
                    if(i-1!=-1 && arr[i-1][j]!='#')
                        v[i*b+j+1].push_back(i*b+j-b+1);
                    if(i+1!=a && arr[i+1][j]!='#')
                        v[i*b+j+1].push_back(i*b+j+b+1);
                    if(j-1!=-1 && arr[i][j-1]!='#')
                        v[i*b+j+1].push_back(i*b+j-1+1);
                    if(j+1!=b && arr[i][j+1]!='#')
                        v[i*b+j+1].push_back(i*b+j+1+1);
                    }
            }
        g[x]=0;
        m++;
        fun(x);
        cout<<"Case "<<k+1<<": "<<m<<endl;
        for(int i=0;i<401;i++)
            v[i].clear();
    }
    return 0;
}
