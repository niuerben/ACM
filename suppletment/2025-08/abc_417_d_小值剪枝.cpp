#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10010, inf = 1e9, mod = 1e9+7;
int dp[10010][1010];
int n,q,p[N],a[N],b[N];


signed main() {
	cin>>n;
    int sum = 0;
    int base = 0;
	for(int i=1;i<=n;i++) {
        cin>>p[i]>>a[i]>>b[i];
        base = max(base,p[i]);
        sum += b[i];
    }

    for(int i=n+1;i>=1;i--){
        for(int j=0;j<=1000;j++){
            if(i==n+1) dp[i][j] = j;
            else{
                if(j>p[i]) {
                    int low = max(j-b[i],0ll);
                    dp[i][j] = dp[i+1][low];
                }
                else dp[i][j] = dp[i+1][j+a[i]];
            }
        }
    }

    cin>>q;
    while(q--){
        int x;cin>>x;
        if(x>base+sum) x -= sum;
        else{
            for(int i=1;i<=n;i++){
                if(x>1000) x-=b[i];
                else {
                    x = dp[i][x];
                    break;
                } 
            }
        }
        cout<<x<<'\n';
    }
    // for(int i=1;i<=n+1;i++){
    //     for(int j=0;j<=10;j++){
    //         cout<<dp[i][j]<<" \n"[j==10];
    //     }
    // }
}
	