#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,X,Y,fa[N],vis[N];

vector<vector<int> > g;
// 对邻表排序，特简单

void dfs(int u,vector<int> path){
    if(u==Y){
        for(int i=0;i<path.size();i++) cout<<path[i]<<" ";cout<<endl;
        return;
    }

    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(vis[v]) continue;
        vis[v] = true;
        path.push_back(v);
        dfs(v,path);
        path.pop_back();
    }
}


signed main() {
    int t;cin>>t;
    while(t--){
        cin>>n>>m>>X>>Y;
        memset(vis,0,sizeof vis);
        g.resize(n+1,vector<int>());
        for(int i=1;i<=m;i++){
            int u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        for(int i=1;i<=n;i++) if(g[i].size()) {
            sort(g[i].begin(),g[i].end());
        }
        vector<int> path={X};
        vis[X] = true;
        dfs(X,path);
        for(int i=0;i<=n;i++) g[i].clear();
    }
    return 0;
}
    