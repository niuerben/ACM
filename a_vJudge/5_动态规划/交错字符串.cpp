#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9, mod = 1e9+7;
int n,m;
string s1,s2,s3;

int dp[N][N];
signed main() {
    cin>>s1>>s2>>s3;
    n = s1.size();
    m = s2.size();
    if(n+m!=s3.size()){
        cout<<"No";
        return 0;
    }

    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        if(s1[i-1]!=s3[i-1]) break;
        dp[i][0] = 1;
    }

    for(int j=1;j<=m;j++){
        if(s2[j-1]!=s3[j-1]) break;
        dp[0][j] = 1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dp[i][j-1]&&s2[j-1]==s3[i+j-1] || dp[i-1][j]&&s1[i-1]==s3[i+j-1]) dp[i][j] = 1;
        }
    }

    cout<<(dp[n][m] ? "Yes" : "No");
    return 0;
}
    
/*
Sample Input1:
aaaa
aabc
aabcaaaa
Sample Output1:
Yes

Sample Input1:
abxf
cckt
acbckxft
Sample Output1:
Yes

*/