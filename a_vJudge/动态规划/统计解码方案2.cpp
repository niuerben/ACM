#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,dp[N];

string s;


int f(int i){

    int ans = 0;
    if(s[i]=='0' || i>n) return 0;
    if(i==n) return 1;
    if(dp[i]) return dp[i];

    // 码长为1
    if(s[i]!='*')
        ans = (ans + f(i+1) ) % mod;
    else
        ans = (ans + 9*f(i+1) ) % mod;

    // 码长为2
    if(s[i]<'3'){
        if(s[i]=='2' && s[i+1] > '6'){}
        else{
            if(s[i]>'0' && s[i+1] != '*') ans = (ans + f(i+2) ) % mod;
            else if(s[i]>'0' && s[i] =='2' && s[i+1] == '*') ans = (ans + 6*f(i+2) ) % mod;
            else if(s[i]>'0' && s[i] < '2' && s[i+1] == '*') ans = (ans + 9*f(i+2) ) % mod;
            else if(s[i]=='*' && s[i+1] != '*') ans = (ans + 2*f(i+2) ) % mod;
            else if(s[i]=='*' && s[i+1] == '*') ans = (ans + 26*f(i+2) ) % mod;
        }
    }


    return dp[i] = ans;
}

signed main() {
    cin>>s;
    n = s.size();

    cout << f(0);

    return 0;
}
/*
也可以写状态转移方程，状态转移前两个和前一个，记得分类。
*/ 