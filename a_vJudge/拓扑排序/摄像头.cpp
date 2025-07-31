#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510, inf = 1e9, mod = 10000;
int n,m,in[N],ans,cnt;

vector<int> g[N];
map<int,bool> mp;
void topsort(){
    queue<int> q;
    // 没人监控的监控先入列
    for(auto [f,s]:mp) if(!in[f] ) q.push(f);
    
    while(q.size()){
        int u = q.front(); q.pop();
        if(mp[u]) cnt++;

        for(auto v:g[u]){
            in[v]--;

            if(!in[v]) q.push(v);
        }
    }

}

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,m;
        cin>>x>>m;
        mp[x] = true;
        for(int j=1;j<=m;j++){
            int y;cin>>y;
            g[x].push_back(y);
            in[y]++;
        }
    }

    topsort();
    if(cnt==n) cout<<"YES";
    else cout<<n-cnt;
    return 0;
}
    