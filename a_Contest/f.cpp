#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+10, inf = 1e9, mod = 1e9+7;
int n,k,c,ans;

struct Node{
    int v;
    int idx;
};

bool cmp(Node a,Node b){
    return a.v-c*a.idx > b.v-c*b.idx;
}
Node a[N];

signed main() {
    cin>>n>>k>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i].v;
        a[i].idx = i;
    }    

    sort(a+1,a+1+n,cmp);

    for(int i=1;i<=k;i++){
        ans +=a[i].v-(a[i].idx-i)*c;
    }
    cout<<ans;
    return 0;
}
    