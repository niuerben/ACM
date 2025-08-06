#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,in[N],ans;

vector<int> g[N];

bool topsort(){
    int cnt = 0;
    int cntIn = 0;
    queue<int> q;
    for(int i=1;i<=n;i++) if(!in[i]) {
        ans = i;
        cntIn++;
        q.push(i);
    }
    
    if(cntIn!=1) return 0;

    while(q.size()){
        int u = q.front();q.pop();
        cnt++;    
        for(auto v:g[u]){
            in[v]--;
            if(!in[v]) {
                q.push(v);
            }
        }
    }

    return cnt==n;
}

signed main() {

    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        in[v]++;
    }

    if(topsort()) cout<<ans;
    else cout << -1;

    return 0;
}
    