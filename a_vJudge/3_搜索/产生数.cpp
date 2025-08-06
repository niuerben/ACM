#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20, inf = 1e9, mod = 1e9+7;
int k,dp[N],vis[N];
vector<int> g[N];

void f(int raw,int x){
    
    for(int i=0;i<g[x].size();i++){
        int v = g[x][i];
        if(vis[v]) continue;
        vis[v] = true;
        f(raw,v);
        dp[raw]++;
    }

}

signed main() {
    string n;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
    }

    __int128_t ans = 1;
    for(int i=0;i<10;i++) {
        dp[i]=1;
        memset(vis,0,sizeof vis);
        vis[i] = true;
        f(i,i);
    }
   
    

    for(int i=0;i<n.size();i++){
        ans *= dp[n[i]-'0'];
    }
    string ans2;
    while(ans){
        ans2.push_back(ans%10+'0');
        ans/=10;
    }
    reverse(ans2.begin(),ans2.end());
    cout<<ans2;

    return 0;
}
    