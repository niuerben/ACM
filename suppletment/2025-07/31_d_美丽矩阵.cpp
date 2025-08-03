#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10, inf = 1e9, mod = 998244353;
int n,m,Cal[N],inv[N];

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
    cin>>n>>m;
    int res = 1;
    Cal[0] = 1;
    for(int i=1;i<N;i++) Cal[i] = Cal[i-1] * i % mod;
    inv[N-1] = qmi(Cal[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i] = inv[i+1]*(i+1) % mod;

    for(int i=1;i<=m;i++) res = res * ((n*(n-1)+i) % mod) % mod;
    res = res * inv[m] % mod;
    cout << res;
    return 0;
}
    