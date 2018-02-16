#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
#include<vector>
#include<stdio.h>
using namespace std;
template<class typ>

class grater1{
public:
	bool operator()(const typ & a,const typ & b){
		pair<int,int> p=(pair<int,int>)a;
		pair<int ,int> p1=(pair<int ,int>)b;
		if(p.second>p1.second){
			return true;
		}
		return false;
	}

};
int color[501];
int dist[501];
vector<int >arr[501];
vector<int >value[501];
std::priority_queue<pair<int,int>,std::vector<pair<int,int> >,grater1<pair<int,int> > >  q;
int digestra(int s, int t){
	int tmp1;
	std::fill_n(dist, 501,INT_MAX );
	std::fill_n(color, 501, 0);
	color[s]=1;
	dist[s]=0;
	q.push(make_pair(s,dist[s]));
	while(!q.empty()){
		pair<int , int > tmp=q.top();
		q.pop();
		if(color[tmp.first]==2)continue;
		color[tmp.first]=2;
		if(tmp.first==t){
			return tmp.second;
		}
		for(int i=0 ; i<arr[tmp.first].size() ; i++){
			tmp1=(value[tmp.first][i] > dist[tmp.first] || tmp.first==s) ? value[tmp.first][i]:dist[tmp.first];
			if(color[arr[tmp.first][i]]==0){color[arr[tmp.first][i]]=1;
				dist[arr[tmp.first][i]]=tmp1;
				q.push(make_pair(arr[tmp.first][i],dist[arr[tmp.first][i]]));
			}
			if(color [arr[tmp.first][i]]==1 && dist[arr[tmp.first][i]]>tmp1){ dist[arr[tmp.first][i]]=tmp1;
			q.push(make_pair(arr[tmp.first][i],dist[arr[tmp.first][i]]));
			}
		}

	}
}
int main(){

	int m,k,i1,i2,i3;
	int n;
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++){
		for(int i=0 ; i<501 ; i++){
			value[i].clear();
			arr[i].clear();
		}
	scanf("%d %d",&m,&k);
	for(int j=0 ; j<k;j++){
		scanf("%d %d %d",&i1,&i2,&i3);
		arr[i1].push_back(i2);
		value[i1].push_back(i3);
		arr[i2].push_back(i1);
		value[i2].push_back(i3);
	}
	scanf("%d",&i1);
	digestra(i1,-1);
	printf("Case %d:\n",i+1);
	for(int j=0 ; j<m ; j++){
		if(dist[j]==INT_MAX)printf("Impossible\n");
		else
		printf("%d\n",dist[j]);
	}
	}

	return 0;
}
