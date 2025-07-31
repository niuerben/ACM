#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,firstPerson;

map<int,int> fa,secret;
vector<int> ans;

struct Node{
    int u,v,t;
    bool operator<(const Node& other)const{
        return t<other.t;
    }
};

void build(){
    for(int i=0;i<=n;i++){
        fa[i]=i;
        secret[i]=false;
    }
    fa[firstPerson] = 0;
    secret[0]=true;
}

int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
void uni(int x,int y){
    int fx = find(x), fy = find(y);
    if(fx!=fy){
        fa[fx] = fy;
        secret[fy] |= secret[fx];
    }
}

signed main() {
    cin>>firstPerson>>n>>m;

    vector<Node> a(m);
    for(int i=0;i<m;i++){        
        cin>>a[i].u>>a[i].v>>a[i].t;
    }
    sort(a.begin(),a.end());

    build();

    for(int l=0,r=0;l<m;){
        r = l;
        while(r+1<m && a[l].t==a[r+1].t) r++;

        for(int i=l;i<=r;i++){
            uni(a[i].u,a[i].v);
        }

        for(int i=l;i<=r;i++){
            int u = a[i].u;
            int v = a[i].v;
            if(!secret[find(i)]){
                fa[u]=u;
            }
            if(!secret[find(v)]){
                fa[v]=v;
            }
        }
        l = r+1;
    }

    for(int i=1;i<=n;i++){
        if(secret[find(i)])
            ans.push_back(i);
    }
    for(auto &i:ans) cout<<i<<" ";
    return 0;
}
    