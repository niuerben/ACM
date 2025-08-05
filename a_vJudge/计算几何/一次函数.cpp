#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;

signed main() {
    int t;cin>>t;
    while(t--){
        cin>>n;
        if(n==0) cout<<0<<'\n';
        else {
            int fz = n;
            int fm = 2*(n+1);
            int d = __gcd(fz,fm);
            fz /= d;
            fm /= d;
            printf("%lld/%lld\n",fz,fm);
        }
    }
    return 0;
}
    