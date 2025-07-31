#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,ans;
int dp[1010];

signed main() {
    string s,t;
    cin>>s>>t;
    n = s.size();
    m = t.size();
    ans = 0;

    dp[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(s[i-1]==t[j-1]) dp[j] += dp[j-1];
        }
    }
    
    
    cout << dp[m];

    return 0;
}

/*
for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            if(s[i-1]==t[j-1]) dp[i][j] += dp[i-1][j-1];
        }
    }
*/