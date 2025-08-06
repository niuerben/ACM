#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m,a[N],b[N];
bool vis[N];

// cnt表示第cnt个排列数
void permutation(int cur,int cnt){
    if(cnt>m){
        for(int i=1;i<=m;i++) cout<<b[i]<<" \n"[i==m];
        return;
    }

    for(int i=cur+1;i<=n;i++){
        vis[a[i]] = true;
        b[cnt] = a[i];
        permutation(i,cnt+1);
        vis[a[i]] = false;
    }
}

signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    permutation(0,1);

    return 0;
}
    