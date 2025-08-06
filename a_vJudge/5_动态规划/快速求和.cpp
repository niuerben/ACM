#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10, inf = 1e9, mod = 1e9+7;
int n,m,num[50][50],dp[50][N];

string s;

// dp(i,k)← (j<i) min dp(j,k−num(j+1,i))+1

signed main() {
    cin>>s;
    cin>>n;
    
    for(int i=0;i<=s.size();i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = inf;
        }
    }

    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<=s.size();j++){
            num[i][j] = num[i][j-1]*10+s[j-1]-'0';
        }
    }

    dp[0][0] = -1;

    for(int i=1;i<=s.size();i++){
        for(int k=0;k<=n;k++){
            for(int j=i-1;j>=0 && num[j][i]<=k;j--){    
                if(s[j]!='0' && i-j>9) break;           
                dp[i][k] = min(dp[i][k],dp[j][k-num[j][i]]+1);
            }
        }
    }

    if(dp[s.size()][n]>=50) cout<<-1;
    else cout << dp[s.size()][n];
    return 0;
}
    