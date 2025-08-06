#include<bits/stdc++.h>
using namespace std;
const int N = 4e5+10, inf = 1e9, mod = 10000;
int n,m,s,t,t0,in[N],ans;
struct Node{
    int v,w;
};

struct Dp{
    int w,cnt;
};

Dp dp[N];

vector<Node> g[N];
void topsort(){
    queue<int> q;
    q.push(s);
    dp[s].cnt = 1;

    while(q.size()){
        int u = q.front(); q.pop();

        if(u==t){
            ans = (dp[u].w + (dp[u].cnt-1) * t0) % mod;
            break;
        }

        for(auto [v,w]:g[u]){
            in[v]--;
            dp[v].cnt = (dp[v].cnt + dp[u].cnt) % mod;
            // 细节递推式w需要*dp[u].cnt，表示u结尾的所有状态，每给状态都能经过边u->v
            dp[v].w = (dp[u].w + dp[v].w + w*dp[u].cnt) % mod;
            // 每次更新答案，到达终点后+一次
            if(!in[v]) {
                q.push(v);
            }
        }
    }

}

signed main() {
    cin>>n>>m>>s>>t>>t0;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        in[v]++;
    }

    topsort();
    // for(int i=1;i<=n;i++) cout<<dp[i].cnt<<" "<<dp[i].w<<endl;
    cout<<ans;
    return 0;
}
    