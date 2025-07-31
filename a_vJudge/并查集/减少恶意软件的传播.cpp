#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,k,a[N],ans;

map<int,int> fa,Size,virus,infect,res;
map<pair<int,int>,int> vis;
int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
void uni(int x,int y){
    int fx = find(x), fy = find(y);
    if(fx!=fy){
        Size[fy]+=Size[fx];
        fa[fx] = fy;
    }
}

signed main() {
    cin>>n>>k;
    
    for(int i=1;i<=n;i++){
        fa[i] = i;
        Size[i] = 1;
        virus[i] = false;
        infect[i] = -1;
    }

    for(int i=1;i<=k;i++){
        cin>>a[i];
        virus[a[i]] = true;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>vis[{i,j}];
            if(vis[{i,j}]==1 && !virus[i] && !virus[j]) uni(i,j);
        }
    }

    // 没感染infect=-1,没救了infect=-2
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(virus[j]) continue;
            if(vis[{a[i],j}] ) {
                if(infect[j]==-1) infect[j] = a[i];
                else if(infect[j] !=-1 && infect[j]!=i) infect[j] = -2;
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(fa[i]==i && infect[i]>0) res[infect[i]]+=Size[i]; 
        ans = max(res[infect[i]],ans);
    }

    cout<<ans;
    return 0;
}