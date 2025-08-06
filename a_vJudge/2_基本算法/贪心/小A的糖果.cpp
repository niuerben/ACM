#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,x,a[N],ans;

signed main() {
    cin>>n>>x;

    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++){
        if(i==1){
            if(a[1]>=a[2]) {
                i=2;
                ans+=a[1];
            }
            else{
                i=3;
                ans+=a[2];
            }
        }
        else{
            if(a[i]+a[i+2] >= a[i+1]+a[i+3]){
                i++;
                ans+=a[i];
            }
            else{
                i+=2;
                ans+=a[i+1];
            }
        }
    }
    cout<<ans;
    return 0;
}
    