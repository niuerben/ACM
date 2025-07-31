#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,k,days[N],cost[N],duration[]={0,1,7,30},dp[N];

int f(int i){
    int ans = __INT64_MAX__;
    
    if(i==n) return 0;
    if(dp[i]) return dp[i];
    
    for(int k=1,j=i;k<=3;k++){
        // 定位到通行证结束期
        while(j<n && days[i]+duration[k]>days[j]) j++;
        /*
        3    4    9    20    50
        ↑         |
        curi       |
        j---------->
        */ 
       
       ans = min(ans,cost[k]+f(j));
    }
    
    // 记忆化缓存数组
    return dp[i] = ans;
}


signed main() {
    cin>>n;
    for(int i=1;i<=3;i++) cin>>cost[i];
    for(int i=1;i<=n;i++) cin>>days[i];

    cout << f(0);
}
    