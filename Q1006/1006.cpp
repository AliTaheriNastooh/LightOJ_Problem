#include<stdio.h>
long long int a, b, c, d, e, f;
long long int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    return( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    long long int arr[100000];
    while( cases!=0 ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        arr[0]=a%10000007;
        arr[1]=b%10000007;
        arr[2]=c%10000007;
        arr[3]=d%10000007;
        arr[4]=e%10000007;
        arr[5]=f%10000007;
        if(n<6) {

            printf("Case %d: %lld\n", ++caseno, arr[n]);
        }else{
            for(int i=6 ; i<=n ; i++){
                arr[i]=(arr[i-1] + arr[i-2] + arr[i-3] + arr[i-4] + arr[i-5] + arr[i-6])%10000007;
            }
        printf("Case %d: %lld\n", ++caseno, arr[n] );

        }
        cases--;
    }
    return 0;
}
