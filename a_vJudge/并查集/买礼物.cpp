#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505, M = 3e6+10, inf = 1e9, mod = 1e9+7;
int n,m,A,a[N][N],fa[N],cnt,ans;

// 用结构体数组存边
struct Edge{
    int u;
    int v;
    int w;  // 边权
    bool operator<(Edge& other)const{
        return w<other.w;
    }
};
Edge edge[M];


void build(){
    for(int i=1;i<=n;i++) fa[i]=i;
}

int find(int x){
    if(x!=fa[x]) return fa[x] = find(fa[x]);
    return fa[x]; 
}


int kruskal(){
    // 按边权排序
    sort(edge+1,edge+1+m);
    build();
    for(int i=1;i<=m;i++){
        // 连接n-1条边即可结束
        if(cnt==n-1) break;
        int fu = find(edge[i].u);
        int fv = find(edge[i].v);
        if(fu==fv) continue;
        // 贪心连接所有最短边
        fa[fu] = fv;
        ans += edge[i].w;
        cnt++;
    }
    return cnt==n-1? ans:-1;
}

signed main() {
    cin>>A>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            edge[++m]={i,j,A};
            edge[++m]={j,i,A};
            if(a[i][j]) edge[++m]={i,j,a[i][j]};
        }
    }
    ans = A;
    cout<<kruskal();

    return 0;
}
    