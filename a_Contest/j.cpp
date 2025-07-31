#include<bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define int long long
typedef pair<int,int> pll;
const int N = 510,inf = 0x3f3f3f3f3f3f3f3f;
int n,a1,a2,b1,b2;

const int mod = 1e9+7;

signed main() {
    int t;cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int ans =-1;
        int mi = min(x,y);
        if((x+y)%mi==0){
            int k = (x+y)/mi;
            ans = log2(k)==(int)log2(k)? log2(k) : -1;
        }
        cout<<ans<<'\n';
    }
    

    return 0;
}
