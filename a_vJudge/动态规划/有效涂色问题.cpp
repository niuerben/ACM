#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9, mod = 1e9+7;
int n,m;
int dp[N][N];

signed main() {
    cin>>n>>m;

    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = (dp[i-1][j-1] * (m-j+1) % mod +dp[i-1][j] * j % mod) % mod;
        }
    }
    // cout << dp[n][m];
    // 动规表
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            cout<<dp[i][j]<<" \n"[j==m];
    return 0;
}
/*
Sample Input:
5 3
Sample Output:
1 0 0 0
0 3 0 0
0 3 6 0
0 3 18 6
0 3 42 36
0 3 90 150

*/