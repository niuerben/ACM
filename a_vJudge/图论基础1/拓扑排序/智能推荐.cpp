#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4+10, inf = 1e11;
int n,k,p,m,in[N],ans,arrive[N];

struct Node{
    int v;
    int d;
};

vector<int> g[N];
map<int,bool> mp;
queue<Node> q;
void topsort(){
    
    // 先做一遍for循环，找到那些点，再把延伸出来的点的入度−1，如果这些点的入度−1后变为入度为0的点，那么再做同样的处理。
    for(int i=1;i<=n;i++) if(!in[i] && !mp[i]) for(auto v:g[i]) if(in[i]) in[i]--;
    int cnt = 0;
    while(q.size()){
        auto [u,d] = q.front(); q.pop();
        cnt++;
        
        if(u==k) {
            cout<<d;
            return;
        }

        for(auto v:g[u]){
            in[v]--;
            if(!in[v]) {
                
                q.push({v,d+1});
            }
        }
    }

    cout<<-1;
}

signed main() {
    cin>>n>>k>>p;
    for(int i=1;i<=p;i++){
        int x;cin>>x;
        q.push({x,0});
        mp[x] = true;
    }

    cin>>m;
    // 非常经典的建图
    for(int i=1;i<=m;i++){
        int u,s;
        cin>>u>>s;
        for(int j=1;j<=s;j++){
            int v;cin>>v;
            g[v].push_back(u);
            in[u]++;
        }
    }

    topsort();
    return 0;
}
    