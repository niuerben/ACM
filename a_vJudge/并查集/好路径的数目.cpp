#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,ans; 
vector<int> w;
map<int,int> fa,ma,cnt;
struct Node{
    int u,v;
    bool operator<(const Node& other)const{
        return max(w[u],w[v]) < max(w[other.u],w[other.v]);
    }
};
vector<Node> edge;

int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}

signed main() {
    cin>>n>>m;
    // resize开辟指定空间，并初始化；reverse仅预分配容量，不初始化元素。
    w.resize(n+1,0ll);
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        fa[i]=i;
        ma[i]=w[i];
        cnt[i]=1;
    }

    edge.reserve(m+1);
    for(int i=1;i<=m;i++){
        cin>>edge[i].u>>edge[i].v;
    }

    sort(edge.begin()+1,edge.begin()+1+m);
    for(int i=1;i<=m;i++){
        int u = edge[i].u;
        int v = edge[i].v;
        int fu = find(u);
        int fv = find(v);
        if(ma[fu]!=ma[fv]){
            if(ma[fu]>ma[fv]) {
                fa[fv] =fu;
            }
            else {
                fa[fu]=fv;
            }
        }
        else {
            ans+=cnt[fu]*cnt[fv];
            cnt[fv]+=cnt[fu];
            fa[fu]=fv;
        }
    }

    ans+=n;
    cout<<ans;
    return 0;
}
    