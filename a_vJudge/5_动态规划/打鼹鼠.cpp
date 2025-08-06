#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4+10, inf = 1e9, mod = 1e9+7;
int n,m,ans;
// 以i结尾能打死最大鼹鼠
int dp[N];
struct Node{
    int t;
    int x,y;
};
Node node[N];

signed main() {
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>node[i].t>>node[i].x>>node[i].y;
    }

    for(int i=1;i<=m;i++){
        dp[i] = 1;
        for(int j=1;j<i;j++){
            if(node[i].t-node[j].t >= abs(node[i].x-node[j].x)+abs(node[i].y-node[j].y)) 
                dp[i] = max(dp[i],dp[j]+1);
        }
        ans = max(dp[i],ans);
    }

    cout << ans;
    return 0;
}
    