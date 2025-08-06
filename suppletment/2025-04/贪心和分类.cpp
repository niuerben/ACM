#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int n,m,a[10];


signed main() {
    int t;cin>>t;
    while(t--){
        int ans = 0;
        int sum = 0;
        int res = 0;
        for(int i=1;i<=5;i++) {
            cin>>a[i];
            sum+=a[i];
        }
        // 5(4321)
        m = min(sum/2,a[5]);
        res += m;
        a[5] -= m;
        sum -= m*2;

        // 4 2
        m = min({a[2],a[4],sum/2});
        res += m;
        a[2]-=m;
        a[4]-=m;
        sum-=m*2;
        
        // 3 3
        m = min(a[3]/2,sum/2);
        res += m;
        a[3]-=m*2;
        sum-=m*2;

        // 2 2 2
        m = min(a[2]/3,sum/3);
        res+=m;
        a[2]-=m*3;
        sum-=m*3;

        // 3 2 1
        m = min({a[2],a[3],sum/3});
        res+=m;
        a[2]-=m;
        a[3]-=m;
        sum-=m*3;

        // 4 1 1
        m = min({a[4],sum/3});
        res+=m;
        a[4]-=m;
        sum-=m*3;
        
        // 2 2 1 1
        m = min({a[2]/2,sum/4});
        res+=m;
        a[2]-=m*2;
        sum-=m*4;

        // 3 1 1 1
        m = min({a[3],sum/4});
        res+=m;
        a[3]-=m;
        sum-=m*4;

        // 2 1 1 1 1 1 1
        m = min({a[2],sum/5});
        res+=m;
        a[2]-=m;
        sum-=m*5;

        
        cout<<res+sum/6<<'\n';
    }
    return 0;
}