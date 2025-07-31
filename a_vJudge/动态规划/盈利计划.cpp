#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 220, inf = 1e9, mod = 1e9+7;
int n,m,group[N],profit[N],sumProfit,dp[N][N][N];


signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>group[i]>>profit[i];
        sumProfit+=profit[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=sumProfit;k>=0;k--){
                if(j+group[i]<=m && k+profit[i]<=sumProfit)
                    dp[i][j][k] = max(dp[i][j][k],dp[i-1][j+group[i]][k+profit[i]]);
            } 
        }
    }
    return 0;
}
        