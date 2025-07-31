#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 210, inf = 1e9, mod = 1e9+7;
int n,m,x,y,k,dp[N][N][N];

double f(int i,int j,int k){ 
    if(i<0 || i>=n || j<0 || j>=n) return 0;
    if(dp[i][j][k]) return dp[i][j][k];

    if(k==0) return 1;

    dp[i][j][k] += f(i-2,j-1,k-1)/8;
    dp[i][j][k] += f(i-2,j+1,k-1)/8;
    dp[i][j][k] += f(i+2,j-1,k-1)/8;
    dp[i][j][k] += f(i+2,j+1,k-1)/8;
    dp[i][j][k] += f(i-1,j-2,k-1)/8;
    dp[i][j][k] += f(i-1,j+2,k-1)/8;
    dp[i][j][k] += f(i+1,j-1,k-1)/8;
    dp[i][j][k] += f(i+1,j+1,k-1)/8;

    return dp[i][j][k];
}

signed main() {
    cin>>n>>x>>y>>k;

    cout << f(x,y,k);
    return 0;
}
    