#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9, mod = 1e9+7;
int n,m,ans = inf;
int dp[N][N];

signed main() {
    string s1,s2;
    cin>>s1>>s2;
    n = s1.size();
    m = s2.size();

    for(int i=1;i<=n;i++) dp[i][0] = i;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j]+1; 
        }
    }
    // for(int j=1;j<=m;j++) ans=min(ans,dp[n][j]);
    // 动规表
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            cout<<dp[i][j]<<" \n"[j==m];
    return 0;
}
    
/*
Sample Input:
abdf
dfxxabYYabfzz
Sample Output:
                    s2[0~j-1]任意后缀
s[0~i-1]任意前缀    0 0 0 0 0 0 0 0 0 0 0 0 0 0
                    1 1 1 1 1 0 1 1 1 0 1 1 1 1
                    2 2 2 2 2 1 0 2 2 1 0 2 2 2
                    3 2 3 3 3 2 1 3 3 2 1 3 3 3
                    4 3 2 4 4 3 2 4 4 3 2 1 4 4
*/