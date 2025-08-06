#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9, mod = 1e9+7;
int n,m,a[N][N],vis[N][N];
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};

void dfs(int i,int j){
    vis[i][j]=true;

    // 标记所有边界0
    for(int k=0;k<4;k++){
        int x = i+dirx[k];
        int y = j+diry[k];
        if(x>=1 && x<=n && y>=1 && y<=n && !vis[x][y] && a[x][y]==0)
            dfs(x,y);
    }
}
    
signed main() {
    cin>>n;
    // 输入
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }

    // 处理边界0
    for(int i=1;i<=n;i++){
        if(!vis[i][1] && a[i][1]==0) dfs(i,1);

        if(!vis[i][n] && a[i][n]==0) dfs(i,n);

        if(!vis[1][i] && a[1][i]==0) dfs(1,i);

        if(!vis[n][i] && a[n][i]==0) dfs(n,i);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==0 && !vis[i][j]) a[i][j]=2;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" \n"[j==n];
        }
    }
    return 0;
}
    