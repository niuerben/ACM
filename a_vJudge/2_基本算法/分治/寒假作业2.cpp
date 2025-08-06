#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,k,cnt,a[N];

signed main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    for(int i=1;i<=n;i++){
        int res = 0;
        for(int j=i;j<=n;j++){
            res += a[j];
            if(res >= k*(j-i+1)) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
    