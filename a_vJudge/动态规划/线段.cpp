#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,l[N],r[N];
int dp[N][2];

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];

    l[0]=r[0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0] = min(dp[i-1][0]+abs(r[i-1]-l[i]),dp[i-1][1]+abs(l[i-1]-l[i]))+(i!=1)+abs(l[i]-r[i]);
        dp[i][1] = min(dp[i-1][0]+abs(r[i-1]-r[i]),dp[i-1][1]+abs(l[i-1]-r[i]))+(i!=1)+abs(l[i]-r[i]);
    }
    cout<<min(dp[n][0]+abs(n-r[n]),dp[n][1]+abs(n-l[n]));
    // for(int i=0;i<=n;i++){
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    // }
    return 0;
}
    