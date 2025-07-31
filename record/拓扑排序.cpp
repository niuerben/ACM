#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9+7;
int n,m,q,a[N],d[N];
vector<int> g[N];

signed main(){
    cin>>m;
    while(m--){
        char u,v;
        cin>>u>>v;
        g[u].push_back(v);
        d[v]++;
    }

    queue<int> q;
    for(int i='a';i<='d';i++)
        if(!d[i]) q.push(i);
    
    while(q.size()){
        char u = q.front();q.pop();
        cout<<u<<" ";
        for(auto &v:g[u]){
            d[v]--;
            if(!d[v]) q.push(v);
        }
    }


    return 0;
}
