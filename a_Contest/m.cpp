#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N = 3e5+10;
int a[N],b[N];

bool check(int k){
    int l=-LONG_LONG_MAX,r=LONG_LONG_MAX;
    for(int i=1;i<=n;i++){
        l = max(l,a[i]-k*b[i]);
        r = min(r,a[i]+k*b[i]);
    }
    return l<=r;
}

void solve(){
    
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    int ans = 0;
    int l=0ll,r=1e9;
    while(l <= r){
        int mid = l + (r - l >> 1);
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << ans << endl; 
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    // cout<<res<<endl;
    return 0;
} 