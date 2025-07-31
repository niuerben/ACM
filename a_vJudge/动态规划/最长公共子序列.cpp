#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,ans;
int dp[1010][1010];

signed main() {
    string s,t;
    while(cin>>s>>t){
        s = " "+s;
        t = " "+t;
        memset(dp,0,sizeof dp);
        ans = 0;
        for(int i=1;i<s.size();i++){
            for(int j=1;j<s.size();j++){
                dp[i][j] = max({dp[i-1][j-1]+(s[i]==t[j]),dp[i-1][j],dp[i][j-1]});
                ans = max(dp[i][j],ans);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
尝试函数
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,ans;
int dp[1010][1010];
string s,t;
int f(int i,int j){
    int ans = 0;
    if(i==0 || j==0){
        if(s[i]==t[j]) return 1;
        else return 0;
    }
    if(dp[i][j]) return dp[i][j];

    return dp[i][j] = max({f(i-1,j),f(i,j-1),f(i-1,j-1)+(s[i]==t[j])});
}
    

signed main() {
    
    cin>>s>>t;
    n = s.size();
    m = t.size();
    ans = 0;
    
    cout << f(n-1,m-1);
    
    return 0;
}
    
*/