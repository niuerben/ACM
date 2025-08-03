#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,X,Y,fa[N],vis[N];

vector<vector<int> > g;

int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
void uni(int x,int y){
    int fx = find(x), fy = find(y);
    if(fx!=fy)
        fa[fx] = fy;
}

void dfs(int u,string path){
    if(u==Y){
        for(int i=0;i<path.size();i++) cout<<path[i]<<" ";cout<<endl;
        return;
    }

    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(vis[v]) continue;
        if(find(v)==find(Y)) {
            vis[v] = true;
            char tmp = v+'0';
            dfs(v,path+tmp);
        }
    }
}


signed main() {
    int t;cin>>t;
    while(t--){
        cin>>n>>m>>X>>Y;
        for(int i=1;i<=n;i++) fa[i]=i;
        memset(vis,0,sizeof vis);
        g.resize(n+1,vector<int>());
        for(int i=1;i<=m;i++){
            int u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            uni(u,v);
        }
        
        for(int i=1;i<=n;i++) if(g[i].size()) {
            sort(g[i].begin(),g[i].end());
        }
        string path(1,X+'0');
        vis[X] = true;
        dfs(X,path);
        for(int i=0;i<=n;i++) g[i].clear();
    }
    return 0;
}
    