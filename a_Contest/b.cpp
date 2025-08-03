#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10, inf = 1e9, mod = 998244353;
int n,m,a[N],b[N];
map<int,int> mp;

signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    for(int i=1;i<=m;i++) {
        cin>>b[i];
        if(mp[b[i]]) mp[b[i]]--;
    }

    for(auto [c,cnt]:mp) {for(int i=1;i<=cnt;i++) cout<<c<< " ";}
    return 0;
}
    