#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,ans;
// 以i下标结尾，不一定包括s[i]的子序列个数（原：以i下标结尾子序列个数）
int dp[N];
// 字符i最后出现位置
int last[N];
// 以i下标结尾，不一定包括s[i]的子序列个数
int sum[N];

string s;

signed main() {
    
    cin>>s;
    dp[0] = 1;
    ans = 1;
    for(int i=1;i<s.size();i++){

        dp[i] = 1;
        int j = last[s[i]]-1;
        if(j>=0){
            dp[i] += dp[i-1] - dp[j];
            // dp[i] += sum[i-1] - sum[j];
        }
        else {
            dp[i] += dp[i-1];
            // dp[i] += sum[i-1];
        };
        
        ans = (ans + dp[i]) % mod;
        // sum[i] = (sum[i-1] + dp[i]);
        /*
        利用前缀和把算法由O(n^2)优化为O(n)
        一开始的想法dpi代表的是以i下标结尾的子序列个数，后来发现最优算法复杂度是O(n)，于是考虑前缀和。
        引入sum[N]数组后又发现dpi累加后可以直接替代sum数组，于是修改动态转移方程的状态。如果一开始就
        考虑以i下标结尾，不一定包括s[i]的子序列个数，感觉根本想不出来，特别是不知道前缀和怎么处理
        */ 
        dp[i] = ans;
        last[s[i]] = i;
    }
    cout << ans;
    return 0;
}
    