#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10,inf = 1e9;
int n,m,a[30][30],sum,ans,vis[30][30];

void dfs(int i,int j,int cur){
    if(j > m) i++, j = 1;   // 一行一行dfs
    if(i > n){
        ans = max(ans, sum ^ cur);
        return;
    }

    if(vis[i][j]) {
        dfs(i,j+1,cur);
        return;
    }

    // 不放骨牌
    dfs(i,j+1,cur);

    // 向右放骨牌
    if(j < m && !vis[i][j+1]){
        vis[i][j] = vis[i][j+1] = 1;
        dfs(i,j+2,cur^a[i][j]^a[i][j+1]);
        vis[i][j] = vis[i][j+1] = 0;
    }

    // 向下放骨牌
    if(i < n && !vis[i+1][j]){
        vis[i][j] = vis[i+1][j] = 1;
        dfs(i,j+1,cur^a[i][j]^a[i+1][j]);
        vis[i][j] = vis[i+1][j] = 0;
    }
}

signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            sum^=a[i][j];
        }
    }
    ans = 0;
    dfs(1,1,0);
    cout<<ans;
    return 0;
}
