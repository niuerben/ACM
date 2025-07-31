#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m,dp[N];

signed main() {
    cin>>n;

    // 计算第2-n个丑数
    dp[1] = 1;
    // 三指针动态规划
    for(int i=2,i2=1,i3=1,i5=1;i<=n;i++){
        int a = dp[i2]*2;
        int b = dp[i3]*3;
        int c = dp[i5]*5;
        int cur = min({a,b,c});
        dp[i] = cur;
        if(a == cur) {
            i2++;
        }
        if(b == cur) {
            i3++;
        }
        if(c == cur) {
            i5++;
        } 
    }

    for(int i=1;i<=n;i++) cout<<dp[i]<<" \n"[i==n];
    return 0;
}
    