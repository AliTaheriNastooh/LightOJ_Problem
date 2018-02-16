#include <iostream>
using namespace std;

long long fun(int n,int k)
{
	if(k==0)
		return 1;
	return fun(n-1,k-1)*n*n/k;
}

int main()
{
	int n,k,t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>k;
		cout<<"Case "<<i+1<<": "<<fun(n,k)<<endl;
	}
	return 0;
}