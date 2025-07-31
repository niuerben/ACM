#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9+7;
int n,m,q,a[N],s[N],ansi,ansj;



signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>a[i];s[i]=s[i-1]+a[i];}
    cin>>m;
    
    for(int i=1,j=1;j<=n;i++){
        while(s[j]-s[i-1] > m) i++;
        while(s[j]-s[i-1] < m) j++;
        if(s[j]-s[i-1] == m) cout<<i<<" "<<j<<'\n';
    }
    
    return 0;
}

