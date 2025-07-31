#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7+10, inf = 1e9, mod = 998244353;
int n,m,k,Cal[N],inv[N];

int qmi(int a,int k){
    int res=1;
    while(k){
        if(k&1) res = res * a % mod;
        k>>=1;
        a = a * a % mod;
    }
    return res;
}

signed main() {
    cin>>n>>m>>k;

    // 计算阶乘
    Cal[0] = 1;
    for(int i=1;i<N;i++) Cal[i] = Cal[i-1] * i % mod;
    // 计算阶乘逆元
    inv[N-1] = qmi(Cal[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i] = inv[i+1]*(i+1) % mod;

    int r = 2*(m-1) + k - (n*m-1);
    cout<<Cal[m-1] * (Cal[n*m-m] % mod * inv[m*n+r+1-2*m] % mod * inv[m-1-r] % mod) % mod
     * Cal[m] % mod * inv[m-r] % mod * inv[r] % mod;
    return 0;
}
    