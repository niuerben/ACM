#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,s[N],d[N],ans;

struct arr{
    int l,r;
};
arr a[N];

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i].l>>a[i].r;
        d[a[i].l]++;
        d[a[i].r]--;
    }

    for(int i=1;i<N;i++){
        s[i]=s[i-1]+d[i];
        ans=max(ans,s[i]);
    }
    cout<<ans;
    return 0;
}

/*
Sample Input 1:
5
1 4
2 4
3 4
4 5
5 6
Sample Output 1:
3
*/