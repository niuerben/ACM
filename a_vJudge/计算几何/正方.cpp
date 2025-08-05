#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,a[5];

signed main() {
    int t;cin>>t;
    while(t--){
        for(int i=1;i<=4;i++) cin>>a[i];
        sort(a+1,a+5);

        if(a[1]+a[4]!=a[2]+a[3]) cout<<0<<'\n';
        else{
            if(a[1]==a[2] && a[3]==a[4]) {
                if(a[1]==a[3]) cout<<1<<'\n';
                else cout<<4<<'\n';
            }
            else cout<<8<<'\n';
        }
    }
    return 0;
}
    