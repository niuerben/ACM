#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9, mod = 1e9+7;
int n,m,ans,vis[N][N];
char a[N][N];
int dirx[4]={-1,1,0,0};
int diry[4]={0,0,1,-1};

void dfs(int i,int j){
    vis[i][j] = true;

    for(int k=0;k<4;k++){
        int x = i+dirx[k];
        int y = j+diry[k];
        if(vis[x][y]) continue;
        if(x>=1&&x<=n&&y>=1&&y<=m && a[x][y]!='0')
            dfs(x,y);
    }
}

signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j]) continue;
            if(a[i][j]!='0'){
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
    