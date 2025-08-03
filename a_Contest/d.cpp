#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,p[N],a[N],b[N];

signed main() {
    cin>>n;
    int sum = 0;
    int ma = 0;
    for(int i=1;i<=n;i++) {
        cin>>p[i]>>a[i]>>b[i];
        sum += b[i];
        ma = max(a[i],ma);
    }

    int V = ma + sum;

    int q;cin>>q;
    while(q--){
        int x;cin>>x;
        if(x>=V) cout<<x-sum<<'\n';
        else{
            for(int i=1;i<=n;i++){
                if(x>p[i]) x = max(x-b[i],0ll);
                else x+=a[i];
            }
            cout<<x<<'\n';
        }
    }
    return 0;
}
    