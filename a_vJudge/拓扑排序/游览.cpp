#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e5+10, inf = 1e9, mod = 10000;
int n,m,s,t,w0,in[N],ans;
struct Node{
    int v,w;
};
vector<Node> g[N];
void topsort(){
    queue<Node> q;
    q.push({s,0});
    
    while(q.size()){
        auto [u,d] = q.front(); q.pop();

        for(auto [v,w]:g[u]){
            in[v]--;
            // 每次更新答案，到达终点后+一次
            if(v==t) ans = (ans + d + w + w0*(in[v]!=0)) % mod;
            if(!in[v]) {
                if(v==t) q.push({v,ans});
                else q.push({v,(d+w)%mod});
            }
        }
    }

}

signed main() {
    cin>>n>>m>>s>>t>>w0;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        in[v]++;
    }

    topsort();
    cout<<ans;
    return 0;
}
    