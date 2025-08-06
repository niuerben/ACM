#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9, mod = 1e9+7;
int n,m,a[N][N];

// 以i,j结尾最小路径和
int dp[N][N];

int f(int x,int y){

    if(x==1 && y==1) return dp[x][y] = a[x][y];
    if(x==0 && y==0) return 0;
    else if(x==0 || y==0) return __INT64_MAX__;
    if(dp[x][y]) return dp[x][y];

    return dp[x][y] = min(f(x-1,y),f(x,y-1)) + a[x][y];
}

signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    cout << f(n,m) << endl;
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=m;j++)
    //         cout << dp[i][j]<<" \n"[j==m];
    return 0;
}

/*
状态转移方程

memset(dp,0x3f,sizeof dp);
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(i==1&&j==1) dp[i][j] = a[i][j];
        else dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + a[i][j];
    }
}

*/

/*
想象中的表      --->    一维dp
3 7 11 13               3   7  11  13 
5 6 9 18                    ↑  
10 9 15 19              5 ← 6   9  18
17 11 14 19             ...

memset(dp,0x3f,sizeof dp);
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        dp[i] = min(dp[i],dp[i-1]) + a[i][j];
    }
}

cout << dp[n];
*/