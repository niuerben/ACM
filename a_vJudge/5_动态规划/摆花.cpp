#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200, inf = 1e9, mod = 1e6+7;
int n,m,a[N];
// 以i结尾时总共sum个摆法的摆法数
int dp[N][N];

// 尝试函数
int f(int i,int sum){

    int ans = 0;
    if(sum == m) return 1;
    else if(i>n) return 0;
    if(dp[i][sum]) return dp[i][sum];

    for(int k=0;k<=a[i+1];k++){
        if(sum+k>m) continue;
        ans = (ans + f(i+1,sum+k)) % mod;
    }

    return dp[i][sum] = ans;
}

signed main() {
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>a[i];

    cout << f(0,0) << endl;

    cout << dp[0][0]<<endl;
    return 0;
}

/*
尝试函数转化为状态转移方程成功！
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200, inf = 1e9, mod = 1e6+7;
int n,m,a[N];
// 选了第i种花，总共sum个花后摆法的摆法数
int dp[N][N];


signed main() {
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>a[i];

    dp[n][m] = 1;
    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){
            for(int k=a[i+1];k>=0;k--){
                if(k+j>m) continue;
                dp[i][j] = (dp[i][j] + dp[i+1][k+j]) % mod;
            }
        }
    }

    cout << dp[0][0]<<endl;
    return 0;
}
*/


    