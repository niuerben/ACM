#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10,INF = 1e9;

// Kosraju算法
/*int vis[N],sccno[N],cnt,n,m;
vector<int> G[N],rG[N];
vector<int> S;

void dfs1(int u){
    if(vis[u]) return;
    vis[u] = true;
    for(int i=0;i<G[u].size();i++)  dfs1(G[u][i]);
    S.push_back(u);
}

void dfs2(int u){
    if(sccno[u]) return;
    sccno[u] = cnt;
    for(int i=0;i<rG[u].size();i++) dfs2(rG[u][i]);
}

void Kosarajku(int n){
    cnt = 0;
    S.clear();
    memset(sccno,0,sizeof sccno);
    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++) dfs1(i);
    for(int i=n-1;i>=0;i--)
        if(!sccno[S[i]]) {cnt++;dfs2(S[i]);}
}

signed main(){
    while(cin>>n>>m){
        if(!n && !m) break;
        memset(G,0,sizeof G);
        memset(rG,0,sizeof rG);
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            rG[v].push_back(u);
        }
        Kosarajku(n);
        cout << ((cnt==1) ? "Yes\n":"No\n");

    }
    return 0;
}*/

// Tarjan算法


// Edmonds-Karp算法

int n,m,graph[N][N],pre[N],flow[N];

int bfs(int s,int t){
    memset(pre,-1,sizeof pre);
    flow[s] = INF; pre[s] = 0;
    queue<int> Q; Q.push(s);
    while(Q.size()){
        int u = Q.front();Q.pop();
        if(u==t) break;
        for(int i=1;i<=n;i++){
            if(i!=s && graph[u][i]>0 && pre[i] == -1){
                pre[i] = u;
                Q.push(i);
                flow[i] = min(flow[u],graph[u][i]);
            }
        }
    }
    if(pre[t] == -1) return -1;
    return flow[t];
}

int maxflow(int s,int t){
    int Maxflow = 0;
    while(1){
        int flow= bfs(s,t);
        if(flow = -1) break;
        int cur = t;
        while(cur!=s){
            int father = pre[cur];
            graph[father][cur] -= flow;
            graph[cur][father] += flow;
        }
        Maxflow += flow;
    }
    return Maxflow;
}

signed main(){
    int s,t;
    cin>>n>>m>>s>>t;
    memset(graph,0,sizeof graph);
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        graph[u][v] += w;
    }
    cout<< maxflow(s,t);
    return 0;
}