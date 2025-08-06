#include<bits/stdc++.h>
using namespace std;
int n, m,cnt,a[200];

int dp[110][20010];
int dfs(int i,int sum){
    // 两个参数两个边界讨论：
    // 讨论菜太多
    if(i==n){
        if(sum==m) return 1;
        else return 0;
    }
    // 讨论钱太多
    else if(sum>=m){
        if(sum==m) return 1;
        else return 0;
    }

    if(dp[i][sum]) return dp[i][sum];

    // 点
    dp[i][sum]+=dfs(i+1,sum+a[i+1]);
    // 不点
    dp[i][sum]+=dfs(i+1,sum);

    return dp[i][sum];
}

void solve(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n;i++) scanf("%d", &a[i]);

    cout << dfs(0,0);


}
int main(){
    solve();
    return 0;
}