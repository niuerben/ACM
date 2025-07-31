#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,a[N],ans;

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++){
        if(i==1) ans+=a[i];
        else{
            if(a[i]>a[i-1]){
                ans+=a[i]-a[i-1];
            }
        }
    }
    cout<<ans;
    return 0;
}
