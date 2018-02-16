/*
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin>>n;
    for (int i = 0; i <n ; ++i) {
        deque<int > dq;
        int size,tmp;
        cin>>size;
        for(int j=0;j<size;j++){
            cin>>tmp;
            dq.push_back(tmp);
        }

        int dif=0;
        int acc=0;

        while(!dq.empty()){
            int max1=-50000,max2=-50000;
            int p1[2]={-1,0},p2[2]={-1,0};
            int i1;
            acc=0;
            for(i1=0;i1<dq.size();i1++){
                acc+=dq[i1];
                if(acc>max1){
                    max1=acc;
                    p1[0]=0;
                    p1[1]=i1;
                }
            }
//            if(acc>max1){
//                max1=acc;
//                p1[0]=0;
//                p1[1]=i1-1;
//            }
            acc=0;
            for(i1=dq.size()-1;i1>=0;i1--) {
                acc += dq[i1];
                if (acc > max1) {
                    max1 = acc;
                    p1[0] =dq.size()-1;
                    p1[1] = i1;
                }
            }
//            if (acc > max1) {
//                max1 = acc;
//                p1[0] =dq.size()-1;
//                p1[1] = i1+1;
//            }
            if(max1!=-50000) {
                dif += max1;
            }
            if(p1[0]==0){
                for (int j = 0; j <p1[1]-p1[0]+1 ; ++j) {
                    dq.pop_front();
                }
            }else{
                for (int j = 0; j <p1[0]-p1[1]+1 ; ++j) {
                    dq.pop_back();
                }
            }
            acc=0;
            for(i1=dq.size()-1;i1>=0;i1--) {
                acc += dq[i1];
                if (acc > max2) {
                    max2 = acc;
                    p2[0] =dq.size()-1;
                    p2[1] = i1;
                }
            }
//            if (acc > max2) {
//                max2 = acc;
//                p2[0] =dq.size()-1;
//                p2[1] = i1+1;
//            }
            acc=0;
            for(int i1=0;i1<dq.size();i1++){
                acc+=dq[i1];
                if(acc>max2){
                    max2=acc;
                    p2[0]=0;
                    p2[1]=i1;
                }
            }
//            if(acc>max2){
//                max2=acc;
//                p2[0]=0;
//                p2[1]=i1-1;
//            }
            if(max2!=-50000) {
                dif -= max2;
            }
            if(p2[0]==0){
                for (int j = 0; j <p2[1]-p2[0]+1 ; ++j) {
                    dq.pop_front();
                }
            }else{
                for (int j = 0; j <p2[0]-p2[1]+1 ; ++j) {
                    dq.pop_back();
                }
            }


        }
        cout<<"Case "<<i+1<<": "<<dif;

    }
    return 0;
}
 */
using namespace std;
#include <bits/stdc++.h>

const int inf = 1 << 30;

const int MN = 111;

int dp[MN][MN];
bool seen[MN][MN];

int go(const vector<int> &nums, int i, int j) {
    if (i > j)
        return 0;

    if (i == j)
        return nums[i];

    if (seen[i][j])
        return dp[i][j];

    seen[i][j] = true;

    int accum = 0;
    int best = -inf;
    for (int k = i; k <= j; ++k) {
        accum += nums[k];
        best = max(best, accum - go(nums, k + 1, j));
    }

    accum = 0;
    for (int k = j; k >=  i; --k) {
        accum += nums[k];
        best = max(best, accum - go(nums, i, k - 1));
    }

    return dp[i][j] = best;

}


void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    memset(seen, 0, sizeof seen);
    printf("%d\n", go(nums, 0, n - 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        printf("Case %d: ", i + 1);
        solve();
    }
    return 0;
}