#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9, mod = 1e9+7;
int n,m,friends[N],enemys[N],sets;

void build(){
    for(int i=1;i<=n;i++){
        friends[i] = i;
        enemys[i] = 0;
        sets++;
    }
}

int find(int x){
    if(x!=friends[x]) return friends[x]=find(friends[x]);
    return friends[x];
}

void uni(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx!=fy) {
        friends[fx]=fy;
        sets--;
    }
}

signed main() {
    cin>>n>>m;
    build();
    while(m--){
        char op;
        int u,v;
        cin>>op>>u>>v;
        if(op=='F'){
            uni(u,v);
        }
        else if(op=='E'){
            if(enemys[u]==0) enemys[u]=v;
            // 合并敌人，敌人的朋友也是敌人
            else uni(v,enemys[u]);
            if(enemys[v]==0) enemys[v]=u;
            // 合并敌人，敌人的朋友也是敌人
            else uni(u,enemys[v]);
        }
    }

    
    cout<<sets;
    return 0;
}
    