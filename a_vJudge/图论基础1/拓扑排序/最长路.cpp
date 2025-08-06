#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4+10, inf = 1e11;
int n,m,in[N],ans,d[N];

struct Edge{
    int to;
    int w;
};

vector<Edge> g[N];
void topsort(){
    queue<int> q;
    // 入度为0的入列
    q.push(1);
    d[1] = 0;
    // 先做一遍for循环，找到那些点，再把延伸出来的点的入度−1，如果这些点的入度−1后变为入度为0的点，那么再做同样的处理。
    for(int i=2;i<=n;i++) if(!in[i]) for(auto [v,w]:g[i]) if(in[v]) in[v]--;
    
    while(q.size()){
        int u = q.front(); q.pop();

        for(auto [v,w]:g[u]){
            in[v]--;
            // 类似迪杰斯特拉的贪心递推
            d[v] = max(d[v],d[u]+w);
            if(!in[v]) q.push(v);
        }
    }

}

signed main() {
    cin>>n>>m;
    // 非常经典的建图
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        in[v]++;
    }

    memset(d,-0x3f,sizeof d);
    topsort();
    if(abs(d[n])>inf) cout<<-1;
    else cout<<d[n];
    return 0;
}
    