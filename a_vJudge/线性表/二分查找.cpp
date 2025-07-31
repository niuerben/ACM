#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7+10,inf = 1e9;
int n,m,a[N];

signed main() {
    cin>>n>>m;

    for(int i = 0; i < n; i ++) {
        a[i] = (i == 0 ? 0 : a[i - 1]) + (int)(100 * sin(n + i)) % 3;
    }

    while(m--){
        int x;cin>>x;
        int i = lower_bound(a,a+n,x)-a;
        if(i==n) i=-1;
        int j = upper_bound(a,a+n,x)-a;
        if(j==n) j=-1;
        cout<<i<<" "<<j<<'\n';
    }
    return 0;
}
    