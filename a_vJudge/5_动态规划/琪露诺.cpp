#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10, inf = 1e9, mod = 1e9+7;
int n,m,l,r,ans=-__INT32_MAX__,a[N];
// 以i结尾最大特定子序和
int dp[N];

signed main() {
    cin>>n>>l>>r;
    m = r-l+1;

    for(int i=0;i<=n;i++){
        cin>>a[i];
    }

    deque<int> q;
    for(int i=1;i<=n-1+r;i++) {
        dp[i] = -__INT32_MAX__;
    }
    q.push_back(0);
    
    for(int i=l;i<=n-1+r;i++){
        dp[i] = max(dp[i],dp[q.front()]+a[i]);

        // 单调队列维护窗口最大值
        while(q.size() && dp[q.back()] < dp[i-l+1]) q.pop_back();
        q.push_back(i-l+1);
        if(i>=m){
            while(q.size() && q.front() <= i-l+1-m) q.pop_front();
        }
        
    }

    for(int i=n;i<=n-1+r;i++) ans = max(ans,dp[i]);
    cout << ans;

    return 0;
}
    