#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 998244353;
int n,m,a[N];

int dp[1010][40010];

int f(int i,int d,int init){


    if(i==n && init) return 1;
    if(dp[i][d+20000]) return dp[i][d+20000];

    for(int k=i+1;k<=n;k++){
        if(!init){
            dp[i][d+20000]+=f(k,0,true);
            // 聊斋志异
            if(a[k]!=a[i]) dp[i][d+20000]+=f(k,a[k]-a[i],true); 
            dp[i][d+20000]+=f(k,d,false);
        }
        else{
            if(a[k]-a[i]==d || k==n+1) dp[i][d+20000]+=f(k,d,true);
        }
    }

    return dp[i][d+20000];
}

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    cout << f(0,0,0) << endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=20;j++){
            cout << dp[i][j+20000] << " \n"[j==20];
        }
    }
    return 0;
}
    