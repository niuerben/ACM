#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m,dp[N];

string s;

int f(int i){

    int ans = 0;
    if(s[i]=='0') return 0;
    if(i>=n-1) return 1;
    if(dp[i]) return dp[i];

    ans += f(i+1);

    if(!(s[i]>'3' && s[i+1]=='0'))
        ans += f(i+2);

    return dp[i] = ans;
}

signed main() {
    cin>>s;
    n = s.size();

    cout << f(0);

    return 0;
}
    