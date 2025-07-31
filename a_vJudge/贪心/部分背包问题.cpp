#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m;
double ans;

struct arr{
    int num,val;
};
arr a[N];

signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].val;
    
    sort(a+1,a+1+n,[](arr a,arr b){
        return (double)a.val/a.num > (double)b.val/b.num;
    });

    int res = m;
    for(int i=1;i<=n;i++){
        double t = min(a[i].num,res);
        ans+=t*a[i].val/a[i].num;
        res-=t;
        if(!res) break;
    }
    printf("%.2f",ans);
    return 0;
}
    