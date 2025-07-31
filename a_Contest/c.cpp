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

    for(int x=0;x<=m;x++){
        if(x*(n-2)+(m-x)*(n-1)==k){
            int res = 0;
            for(int i=1;i<=m-x;i++){
                res = (res + qmi(2*x,m-x-i) % mod * Cal[m-x] % mod * inv[m-x-i] % mod) % mod;
            }
            cout << Cal[m] * inv[m-x] % mod * qmi(n-1,x) % mod * res % mod;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
    