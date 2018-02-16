#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n;
int m;

char a[100];
char b[100];
long long count;
unsigned long long ans2[40][40][40];
long long ans3[40][40];
int temp;

unsigned long long explore2(int i, int j, int l)
{

	if(i == n && j != m) {
		return explore2(i, j+1, l-1);
	}

	if(j == m && i != n) {
		return explore2(i+1, j, l-1);
	}


	if(i == n && j == m && l == 0) {
		return 1;
	}

	if(i == n && j == m && l != 0) {
		return 0;
	}

	if(ans2[i][j][l] != -1) {
		return ans2[i][j][l];
	}

	if(a[i] == b[j]) {
		return ans2[i][j][l] = explore2(i+1, j+1, l -1);
	}

	return ans2[i][j][l] = explore2(i+1, j, l -1) + explore2(i, j+1, l -1);

}
int explore(int i, int j)
{
    if(i==0|| j==0){
        return 0;

    }
    if(ans3[i][j]!=-1){
        return ans3[i][j];
    }else{
    if(a[i-1]==b[j-1]){
        return ans3[i][j]=1+explore(i-1,j-1);
    }
    else{

        return ans3[i][j]=max(explore(i,j-1),explore(i-1,j));
    }
    }
}
int main()
{
	int t;
	long long epic;
	scanf("%d", &t);

	for (int cs = 1; cs <= t ; cs++) {
		scanf("%s", a);
		scanf("%s", b);

		n = strlen(a);
		m = strlen(b);

		memset(ans3, -1, sizeof(ans3));

		temp = explore(n, m);
		memset(ans2, -1, sizeof(ans2));
		epic = explore2(0, 0, n+m-temp);

		printf("Case %d: %d %lld\n",cs,n+m-temp,epic);

	}

}
