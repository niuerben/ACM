#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
// dpi: 必须以结尾的字串最大长度
int n,m,dp[N],ans;

string s;

signed main() {
    cin>>s;
    stack<char> stk;
    // 先算嵌套有效括号串
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') {
            stk.push('(');
        }
        else{
            if(stk.size()) {
                stk.pop();
                dp[i] = dp[i-1] + 2; 
            }
        }
    }

    // 再算并列有效括号串
    for(int i=1;i<=s.size();i++){
        dp[i] += dp[i-dp[i]];
        ans = max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}
    