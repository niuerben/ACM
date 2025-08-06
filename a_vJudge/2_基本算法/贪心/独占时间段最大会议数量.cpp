#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,inf = 1e9;
int n,m,ans;

struct arr{
    int l,r;
};
arr a[N];

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;

    sort(a+1,a+1+n,[](arr a,arr b){
        return a.r == b.r ? a.l<b.l : a.r<b.r;
    });

    int cur = 0;
    for(int i=1;i<=n;i++){
        if(a[i].l < cur) continue;
        if(a[i].r>cur) {
            cur = a[i].r;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

/*
input:
3
1 50
49 51
50 100

output:
2
*/