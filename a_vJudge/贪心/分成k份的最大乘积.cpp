#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9, mod = 1e9+7;
int n,m,ans;

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
    int res = n%m;
    int base = n/m;
    ans = qmi(base,m-res) % mod * qmi(base+1,res) % mod;
    cout<<ans;
    return 0;
}

/*
Sample Input 1:
12 2
Sample Output 1:
36

Sample Input 2:
12 3
Sample Output 2:
64
*/