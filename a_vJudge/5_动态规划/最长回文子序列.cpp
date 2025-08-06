#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9, mod = 1e9+7;
int n,m;
int dp[N][N];

string s;
int f(int l,int r){
    if(l>r) return 0;
    if(l==r) return 1;
    if(l+1==r) return 1+(s[l]==s[r]);

    if(dp[l][r]) return dp[l][r];

    if(s[l]!=s[r]) return dp[l][r] = max(f(l+1,r),f(l,r-1));
    else return dp[l][r] = f(l+1,r-1)+2;

}

signed main() {
    cin>>s;
    n = s.size();
    cout << f(0,n-1);
    
    return 0;
}
    