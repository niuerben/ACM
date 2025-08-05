#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int l[N],r[N],ans;
double n,m,p;

signed main() {
    cin>>n>>m>>p;
    double k1 = m/n;
    for(int i=1;i<m;i++){
        l[i] = ceil(k1*i);
    } 

    for(int i=1;i<m;i++){
        
        r[i] = floor(i*n/(m-p)+p);
    }

    for(int i=1;i<m;i++){
        cout<<l[i]<<" "<<r[i]<<endl;
        ans+=r[i]-l[i]+1;
    }
    cout<<ans;
    return 0;
}
    