#include <iostream>
#include <map>
using namespace std;

int arr[200][101],_max[200][101],n;

int max(int x,int y)
{
	return (x>y) ? x : y;
}

int fun(int x,int y)
{
	if(arr[x+1][y] && _max[x+1][y]==0)
		_max[x+1][y]=fun(x+1,y);
	if(arr[x+1][y+1] && _max[x+1][y+1]==0)
		_max[x+1][y+1]=fun(x+1,y+1);
	_max[x][y]=max(_max[x+1][y+1],_max[x+1][y])+arr[x][y];
	return _max[x][y];
}

int main()
{

	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
		for(int i=0;i<200;i++)
			for(int j=0;j<101;j++)
			{
				arr[i][j]=0;
				_max[i][j]=0;
			}
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)
				cin>>arr[i][j];
		for(int i=n-2;i>=0;i--)
			for(int j=n-i-1;j<n;j++)
				cin>>arr[2*n-i-2][j];
		_max[0][0]=fun(0,0);
		cout<<"Case "<<k+1<<": "<<_max[0][0]<<endl;
	}
	return 0;
}
