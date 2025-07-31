#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20, inf = 1e9, mod = 1e9+7;
int n,m;
double x[N],y[N],d[N][N];
double dp[20][40000];

signed main() {
    cin>>n;
    // 取double数组的极大值
    memset(dp,127,sizeof dp);
    double ans = dp[0][0];
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }

    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            d[j][i] = d[i][j] = hypot(x[i]-x[j],y[i]-y[j]);
        }
    }


    // 初始化起点
    for(int i=1;i<=n;i++) dp[i][1<<(i-1)]=d[0][i];

    // 枚举每一个状态
    for(int k=1;k<(1<<n);k++){
        
        // 枚举每一个当前位置
        for(int i=1;i<=n;i++){
            // 注意含位运算判断相等要加括号，位运算优先级比等于号还低！
            if((k & (1<<(i-1))) == 0) continue;

            // 枚举每一个能到达当前位置的上一个位置
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                if((k & (1<<(j-1))) == 0) continue;
                dp[i][k] = min(dp[i][k],dp[j][k-(1<<(i-1))]+d[i][j]);
            }
        }
    }

    for(int i=1;i<=n;i++) ans=min(ans,dp[i][(1<<n)-1]);
    printf("%.2lf",ans);
    return 0;
}
    