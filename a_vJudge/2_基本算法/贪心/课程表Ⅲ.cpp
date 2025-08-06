#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,ans;

struct arr{
    int f,d;
};
arr a[N];

signed main() {
    int t;cin>>t;
    while(t--){
        cin>>n;
        ans = 0;
        for(int i=1;i<=n;i++){
            cin>>a[i].f>>a[i].d;
        }

        sort(a+1,a+1+n,[](arr a,arr b){
            return a.d==b.d ? a.f<b.f : a.d < b.d;
        });

        int cur = 0;
        for(int i=1;i<=n;i++){
            if(cur+a[i].f<=a[i].d){
                cur+=a[i].f;
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
    