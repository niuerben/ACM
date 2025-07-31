#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int n,m,limit,color[N];

struct Node{
    int to;
    int w;
};
vector<Node> nodes[N];

bool dfs(int u,int c){
    color[u] = c;
    // 尝试给邻居染色
    for(int i=0;i<nodes[u].size();i++){
        int v = nodes[u][i].to;
        // 怨气值太小的不用分层
        if(nodes[u][i].w <= limit) continue;
        // 颜色只会是1或2
        if(!color[v])
            if(!dfs(v,3-c)) return false;
        if(color[v]==c) return false;
    }
    return true;
}

bool check(int mid){
    limit=mid;
    memset(color,0,sizeof color);
    for(int i=1;i<=n;i++){
        if(!color[i])
            // 把没染色的染色，若无色可染，则返回false
            if(!dfs(i,1)) return false;
    }
    return true;
}

int main(){
    cin>>n>>m;
    // 建树
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        nodes[u].push_back({v,w});
        nodes[v].push_back({u,w});
    }
    //二分枚举limit，把所有大于limit的构成二分图
    int l=0,r=1e9;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    
    cout<<l;
}