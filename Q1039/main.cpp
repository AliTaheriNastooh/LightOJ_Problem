#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<string ,bool> map1;
string start1,end1;

int mybfs(){
    queue<pair<int,string > >pq;
    pq.push(make_pair(0,start1));
    while(! pq.empty()){

        pair<int , string > tmp;
        tmp=pq.front();

        pq.pop();
        //cout<<tmp.first<<" "<<tmp.second<<endl;
        if(map1[tmp.second]==1)continue;
        if(tmp.second==end1)return tmp.first;
        map1[tmp.second]=1;
        for(int i=0;i<3;i++){
            string s=tmp.second;
            if(s[i]=='z'){
                s[i]='a';
            }else{
                s[i]=(char)((int)s[i]+1);
            }
            pq.push(make_pair(tmp.first+1,s));

            s=tmp.second;
            if(s[i]=='a'){
                s[i]='z';
            }else{
                s[i]=(char)((int)s[i]-1);
            }
            pq.push(make_pair(tmp.first+1,s));

        }
    }
    return -1;
}


int main() {
    int t;cin>>t;
    for(int i=0;i<t;i++){
        map1.clear();
        cin>>start1;
        cin>>end1;
        int n;cin>>n;
        for(int j=0;j<n;j++){
            string t1;cin>>t1;
            string t2;cin>>t2;
            string t3;cin>>t3;
            string s="";
            for(int i1=0;i1<t1.size();i1++){
                s+=t1[i1];
                for(int j1=0;j1<t2.size();j1++){
                    s+=t2[j1];
                    for(int k1=0;k1<t3.size();k1++){
                        s+=t3[k1];
                        map1[s]=1;
                        s.erase(s.size()-1);
                    }
                    s.erase(s.size()-1);
                }
                s.erase(s.size()-1);
            }
        }
        cout<<"Case "<<i+1<<": "<<mybfs()<<endl;
    }
    return 0;
}