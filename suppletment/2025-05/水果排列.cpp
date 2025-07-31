#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e6+10,mod = 998244353;
int a,o,b,g,dp[N],ans,sum,Cal[N],inv[N];

int qmi(int a,int k){
    int res=1;
    while(k){
        if(k&1) res = res * a % mod;
        k>>=1;
        a = a * a % mod;
    }
    return res;
}

signed main(){
    cin>>a>>o>>b>>g;
    Cal[0] = 1;
    for(int i=1;i<N;i++) Cal[i] = Cal[i-1] * i % mod;
    inv[N-1] = qmi(Cal[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i] = inv[i+1]*(i+1) % mod;

    for(int i=a;i<=a+o;i++){
        sum = (sum + Cal[i-1]*Cal[a+o+b+g-i] % mod * inv[i-a] % mod * inv[a-1] % mod * inv[a+o+g-i] % mod * inv[b] % mod) % mod;
    }
    cout << sum;
    return 0;
}

