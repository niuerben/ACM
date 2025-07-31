#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9, mod = 1e9+7;
int n,m,lose[N],win[N],use[N];
int dp[N][N];

signed main() {
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>lose[i]>>win[i]>>use[i];

    
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            if(j>=use[i]) dp[i][j] = max(dp[i-1][j]+lose[i],dp[i-1][j-use[i]]+win[i]);
            else dp[i][j] = dp[i-1][j]+lose[i];
        }
    }
    cout << 5*dp[n][m];
    // 动规表
    // for(int i=0;i<=n;i++)
    //     for(int j=0;j<=m;j++)
    //         cout<<dp[i][j]<<" \n"[j==m];
    return 0;
}