#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9, mod = 1e9+7;
int c,r,ans;
int a[N][N];

int dp[N][N];

int f(int i,int j){
    int res = 1;
    if(dp[i][j]) return dp[i][j];
    // 上
    if(i-1>0 && a[i-1][j]<a[i][j])
        res = max(res,f(i-1,j)+1);
    // 下
    if(i+1<=c && a[i+1][j]<a[i][j])
        res = max(res,f(i+1,j)+1);
    // 左
    if(j-1>0 && a[i][j-1]<a[i][j])
        res = max(res,f(i,j-1)+1);
    // 右
    if(j+1<=r && a[i][j+1]<a[i][j])
        res = max(res,f(i,j+1)+1);

    return dp[i][j] = res;
}

signed main() {
    cin>>c>>r;

    for(int i=1;i<=c;i++){
        for(int j=1;j<=r;j++){
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=c;i++){
        for(int j=1;j<=r;j++){
            ans = max(ans,f(i,j));
        }
    }
    cout << ans;
    return 0;
}
    