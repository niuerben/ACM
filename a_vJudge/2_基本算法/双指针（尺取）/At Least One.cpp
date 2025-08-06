#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10,inf = 1e9,mod = 998244353;
int n,m,a[N],b[N],f[N],mp[N],sum;


bool check(int i,int j){    
    int cnt = 0;
    for(int k=1;k<=n;k++){
        if((a[k]<i||a[k]>j) && (b[k]<i||b[k]>j)) return false;
    }
    return true;
}

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
   
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            if(check(i,j)) f[j-i+1]++;
        }
    }

    for(int i=1;i<=m;i++) cout<<f[i]<<" \n"[i==m];
    return 0;
}