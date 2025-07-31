#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 210, inf = 1e9, mod = 1e9+7;
int n,m,k,a[N][N];

int dp[N][N][N];
signed main() {
    
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    dp[1][1][a[1][1]%k] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1) continue;
            for(int l=0;l<k;l++){
                int ll = l;
                if(a[i][j]%k > l) ll = l+k;
                int m = a[i][j]%k;
                dp[i][j][l] = dp[i][j-1][ll-m]+dp[i-1][j][ll-m];
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int l=0;l<k;l++){
                cout<<dp[i][j][l]<<", "[l==k-1];
            }
        }
        cout<<endl;
    }

    
    return 0;
}
    