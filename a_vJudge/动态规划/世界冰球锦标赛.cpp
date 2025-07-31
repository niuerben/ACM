#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 60, inf = 1e9, mod = 1e6+7;
int n,m,a[N];
// 以i结尾时总共sum个摆法的摆法数
int dp[N][N];

// 尝试函数
int f(int i,int sum){

    int ans = 0;
    if(sum==0) return 1;
    if(i>n) {
        if(sum>=0) return 1;
        else return 0;
    }


    ans += f(i+1,sum-a[i]);
    ans += f(i+1,sum);

    return ans;
}

signed main() {
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>a[i];

    cout << f(1,m) << endl;

    return 0;
}




    