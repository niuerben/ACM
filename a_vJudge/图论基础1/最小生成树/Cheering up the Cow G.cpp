#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,c[N],fa[N];

struct Node{
    int u,v,w;
};
Node edge[N];

int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
void uni(int x,int y){
    int fx = find(x), fy = find(y);
    if(fx!=fy)
        fa[fx] = fy;
}

int kruskal(){
    sort(edge+1,edge+1+m,[](Node a,Node b){
        return a.w+c[a.u]+c[a.v] < b.w+c[b.u]+c[b.v];
    });
    int cnt = 0;
    int ans = 0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        if(cnt==n-1) break;
        int e1 = find(edge[i].u);
        int e2 = find(edge[i].v);
        if(e1==e2) continue;
        fa[e1]=e2;
        // cout << edge[i].u<<" "<<edge[i].v<<endl;
        if(cnt ==0) ans += c[edge[i].u];
        else if(cnt == n-2) ans += c[edge[i].v];
        ans+=edge[i].w+c[edge[i].u]+c[edge[i].v];
        cnt++;
    }
    return ans;
}

signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }

    for(int i=1;i<=m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }

    

    cout << kruskal();
    return 0;
}
    