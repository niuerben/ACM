#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,d[N],e[N],ne[N],h[N],idx;

priority_queue<int> heap;
void add(int u,int v){
    // 链式前向星idx存的是边的地址
    // e当前内存能到达的节点
    e[idx]=v;
    // ne当前内存的上一条临边地址
    ne[idx]=h[u];
    // 本临边地址
    h[u]=idx++;
    d[v]++;
}

void topsort(){
    for(int i=1;i<=n;i++) if(d[i]==0) heap.push(i);
    
    while(heap.size()){
        int u = heap.top();heap.pop();
        cout<<u<<" ";

        for(int i=h[u];i!=-1;i=ne[i]){
            int v = e[i];
            d[v]--;
            if(!d[v]) heap.push(v);
        }
    }

}

signed main() {
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }

    topsort();
    return 0;
}
    