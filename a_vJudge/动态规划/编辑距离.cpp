#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9, mod = 1e9+7;
int n,m;
int dp[N];

signed main() {
    string s,t;
    cin>>s>>t;
    n = s.size();
    m = t.size();
    int I,D,R;
    I=D=R=1;

    for(int i=0;i<=m;i++) dp[i] = i*D;

    for(int i=1,leftUp,backUp;i<=n;i++){
        leftUp = (i-1)*D;
        dp[0] = i*I;
        // 从左往右更新的时候用leftUp把左上角数据滚过去
        for(int j=1;j<=m;j++){
            backUp = dp[j];
            if(s[i-1]==t[j-1]) dp[j] = leftUp;
            else{
                dp[j] = min({leftUp+R,dp[j-1]+I,dp[j]+D});
            } 
            leftUp = backUp;
        }
    }

    cout<<dp[m];
    return 0;
}


/*
for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = min({dp[i-1][j-1]+R,dp[i][j-1]+I,dp[i-1][j]+D});
            } 
        }
    }
*/