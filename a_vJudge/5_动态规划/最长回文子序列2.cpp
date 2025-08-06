#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,ans;
int dp[1010][1010];

signed main() {
    string s,t;
    cin>>s;
    t = s;
    //  最长回文子序列就是原串和逆串的最长公共子序列
    reverse(t.begin(),t.end());
    s = " "+s;
    t = " "+t;
    memset(dp,0,sizeof dp);
    ans = 0;
    for(int i=1;i<=s.size()/2;i++){
        for(int j=1;j<=s.size()/2;j++){
            dp[i][j] = max({dp[i-1][j-1]+(s[i]==t[j]),dp[i-1][j],dp[i][j-1]});
            ans = max(dp[i][j],ans);
        }
    }
    cout << 2*ans + (s[s.size()/2]!=t[s.size()/2]) << '\n';
    return 0;
}
