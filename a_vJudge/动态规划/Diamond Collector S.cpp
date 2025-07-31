#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10, inf = 1e9, mod = 1e9+7;
int n,m,k,a[N],ans;

int dpl[N],dpr[N];

signed main() {
    cin>>n>>k;

    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+1+n);

    a[0] = a[1];
    for(int i=1,j=1;i<=n;i++){
        // 确定区间
        while(j<=n && a[j]-a[i]<=k) {
            dpl[j]=max(dpl[j-1],j-i+1);
            j++;
        }

    }

    a[n+1] = a[n];
    for(int i=n,j=n;i>=1;i--){
        while(j>=1 && a[i]-a[j]<=k) {
            dpr[j] = max(dpr[j+1],i-j+1);
            j--;
        
        }

    }

    for(int i=1;i<n;i++) ans = max(ans,dpl[i]+dpr[i+1]);
    cout<<ans;
    return 0;
}
    