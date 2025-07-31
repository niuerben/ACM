#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9, mod = 1e9+7;
int n,m,fa[N],sets;
char a[N][N];

void build(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==0) fa[i*m+j]=-1;
            else if(a[i][j]==1) {
                fa[i*m+j]=i*m+j;
                sets++;
            }
        }
    }
}

int find(int x){
    if(x!=fa[x]) return fa[x] = find(fa[x]);
    return fa[x];
}

void uni(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx!=fy) {
        fa[fy] = fx;
        sets--;
    }

}

signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    build();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='W'){
                if(a[i+1][j]=='W' && find(i*m+j)!=find((i+1)*m+j) ) uni(i*m+j,(i+1)*m+j);
                if(a[i][j+1]=='W' && find(i*m+j)!=find(i*m+j+1) ) uni(i*m+j,i*m+j+1);
            }
        }
    }

    cout<<sets;
    return 0;
}
    