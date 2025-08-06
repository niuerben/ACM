#include<bits/stdc++.h>
using namespace std;
const int N = 5010, M = N*(N-1)/2;
int n,m,x[N],y[N],fa[N];

struct Node{
    int u,v;
    double w;
};
Node edge[M];


int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
void uni(int x,int y){
    int fx = find(x), fy = find(y);
    if(fx!=fy)
        fa[fx] = fy;
}

double kruskal(){
    sort(edge+1,edge+1+m,[](Node a,Node b){
        return a.w < b.w;
    });
    int cnt = 0;
    double res = 0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        if(cnt==n-1) break;
        int e1 = find(edge[i].u);
        int e2 = find(edge[i].v);
        if(e1==e2) continue;
        fa[e1]=e2;
        res += edge[i].w;
        cnt++;
    }
    return res;
}

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(i==j) continue;
            edge[++m].u = i;
            edge[m].v = j;
            edge[m].w = hypot(x[i]-x[j],y[i]-y[j]);
        }
    }

    printf("%.2lf",kruskal());
    return 0;
}
    