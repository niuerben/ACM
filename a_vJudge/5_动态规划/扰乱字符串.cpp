#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 210, inf = 1e9, mod = 1e9+7;
int n,m,dp[N][N][N];

string s1,s2;
bool f(int l1,int r1,int l2, int r2){
    if(l1==r1){
        return s1[l1]==s2[l2];
    }
    int len = r1-l1+1;
    if(dp[l1][r1][len]!=-1) return dp[l1][r1][len];

    for(int i=l1,j=l2;i<r1;i++,j++){
        if(f(l1,i,l2,j) && f(i+1,r1,j+1,r2))
            return dp[l1][l2][len] = 1;
    }

    for(int i=l1,j=r2;i<r1;i++,j--){
        if(f(l1,i,r2,j) && f(i+1,r1,j-1,l2))
            return dp[l1][l2][len] = 1;
    }

    return dp[l1][l2][len] = 0;
}


signed main() {
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();
    memset(dp,-1,sizeof dp);
    cout << f(0,n,0,m); 
    return 0;
}
    