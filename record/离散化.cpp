#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9+7;
int n,m,q,a[N],b[N],c[N];

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>a[i];c[i]=a[i];}
    sort(c+1,c+1+n);
    for(int i=1;i<=n;i++) b[i] = lower_bound(c,c+1+n,a[i])-c;

    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    return 0;
}
