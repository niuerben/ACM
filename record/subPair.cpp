#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9+7;
int n,m,q,a[N],cnt;

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    
    for(int i=1,j=1;j<=n;i++){
        while(i<=n && a[j]-a[i] > m) i++;
        while(j<=n && a[j]-a[i] < m) j++;
        if(a[j]-a[i]==m) {
            int k = j+1;
            while(k<=n && a[k]==a[j]) k++;
            cnt += k-j;
        }
    }
    cout<<cnt;
    return 0;
}
