#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,ans;
// dp2i：以i字符为结尾的最长base字串
// len：以下标i为结尾的最长base字串
int len = 1,dp[N];

string s;

signed main() {
    cin>>s;

    dp[s[0]] = 1;
    for(int i=1;i<s.size();i++){
        if(s[i]-'a' == ((s[i-1]-'a' + 1) %26)) len++;
        else len = 1;
        dp[s[i]] = max(len,dp[s[i]]);
    }


    for(int i='a';i<='z';i++) {
        ans+=dp[i];
    }
    cout << ans;
    return 0;
}

/*
zabpxyzab
        以i下标结尾的最长子串：  以i字符结尾的最长子串
z       1                       dp_z = 1
za      2                       dp_a = 2
zab     3                       dp_b = 3
p       1                       dp_p = 1
x       1                       dp_x = 1
xy      2                       dp_y = 2
xyz     3                       dp_z = 3
xyza    4                       dp_a = 4
xyzab   5                       dp_b = 5

*/