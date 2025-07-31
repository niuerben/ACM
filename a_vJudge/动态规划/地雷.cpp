#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 25, inf = 1e9, mod = 1e9+7;
int n,m,a[N],ans,ans2[N],len,fa[N];

vector<int> edge[N];
int dp[N];

void f(int i,int sum){
    if(i==n || i==n+1) {
        if(sum>ans){
            for(int j=1;j<=n;j++) ans2[j] = 0;
            int j=0;
            int k = i;
            if(i==n+1) k = fa[i];
            for(;k!=0;j++,k=fa[k]){
                ans2[j+1] = k;
            }
            len = j;
            ans = sum;
        }
    }

    for(int j=0;j<edge[i].size();j++){
        int v =edge[i][j];
        fa[v] = i;
        f(v,sum+a[v]);

    }

}

signed main() {
    cin>>n;

    for(int i=1;i<=n;i++) cin>>a[i];

    // 建图
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int x;cin>>x;
            if(x) {
                edge[i].push_back(j);
            }
        }
        edge[i].push_back(n+1);
    }

    for(int i=1;i<=n;i++){
        f(i,a[i]);
    }

    for(int i=len;i>=1;i--) cout<<ans2[i]<<" \n"[i==1];
    cout << ans;
    return 0;
}
    