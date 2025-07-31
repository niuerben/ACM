#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,a[N],ans;
// 取i的j大小背包的最大占用空间
int dp[50][N];

signed main() {
    cin>>m;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=m;j>=a[i];j--){
            if(dp[i][j-a[i]]+a[i] <= m)
            /*
                                只取a[i]           确定了a[i-1]后取a[i]    不取a[i]
            */
                dp[i][j] = max({dp[i][j-a[i]]+a[i],dp[i-1][j-a[i]]+a[i],dp[i-1][j]});
            ans = max(dp[i][j],ans);
        }
    }
    cout << m-ans;
    return 0;
}
    
/*
暴力搜索：
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m,ans,a[N];

void f(int i,int res){

    if(i>n) return;
    ans = min(ans,res);

    // 不拿
    f(i+1,res);
    // 拿
    if(res>=a[i+1])
        f(i+1,res-a[i+1]);

}


signed main() {
    cin>>m;
    cin>>n;
    ans = m;

    for(int i=1;i<=n;i++) cin>>a[i];
    
    f(0,m);
    cout << ans;
}
    
*/