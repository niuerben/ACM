#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int n,m;

map<int,int> fa;

int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}

struct Node{
    int u,v,e;
    bool operator<(const Node& other)const{
        return e>other.e;
    }
};

void solve(){
    cin>>n;
    // 建树
    fa.clear();
    
    vector<Node> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].u>>a[i].v>>a[i].e;
    }

    sort(a.begin(),a.end());

    for(int i=0;i<n;i++){
        int u = a[i].u;
        int v = a[i].v;
        int e = a[i].e;
        if(!fa[u]) {
            fa[u]=u;
        }
        if(!fa[v]) {
            fa[v]=v;
        }
        int fu = find(u);
        int fv = find(v);
        if(e==1){
            if(fu!=fv)  fa[fu]=fv;
        }
        else{
            if(fu==fv){
                std::cout<<"NO"<<'\n';
                return;
            }
        }
        
    }
    std::cout << "YES"<<'\n';
    return;
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }

}