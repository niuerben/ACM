#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9;
int n,m,col[N],row[N],d[N],rd[N];
char a[N][N];

int cnt = 0;
int cntQ = 0;
void queen(int cur){
    if(cur == n+1){
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         cout<<a[i][j];
        //     }
        //     cout<<'\n';
        // }
        // cout<<'\n';
        if(cntQ == n) cnt++;
    }

    for(int j=1;j<=n;j++){
        if(row[j] || d[cur-j+n] || rd[cur+j]) continue;
        
        row[j] = true;
        d[cur-j+n] = true;
        rd[cur+j] = true;
        a[cur][j] = 'q';
        cntQ++;
        queen(cur+1);
        cntQ--;
        a[cur][j] = 'x';
        row[j] = false;
        d[cur-j+n] = false;
        rd[cur+j] = false;
    }
}

signed main() {
    cin>>n;
    memset(a,'x',sizeof a);

    queen(1);
    cout<<cnt;
    return 0;
}
    