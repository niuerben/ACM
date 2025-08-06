#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10, inf = 1e9, mod = 1e9+7;
int n,m,a[N],ans;
// 以i结尾最大字串和
int dp[N];

signed main() {
    while(cin>>n){
        for(int i=0;i<=n;i++) dp[i] = 0;
        ans = -__INT64_MAX__;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            dp[i] = max(dp[i-1]+a[i],a[i]);
            ans = max(ans,dp[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
    