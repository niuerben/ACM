#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10, inf = 1e9, mod = 1e9+7;
int n,m,a[N],b[N],c[N],ans;
map<int,int> mp,mp2;

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i] = a[i]+i;
        c[i] = i-a[i];
        mp[b[i]]++;
        mp2[c[i]]++;
    }

    for(auto [num,cnt]:mp){
         ans += cnt*mp2[num];
    }

    cout<<ans;
    return 0;
}
    