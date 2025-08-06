#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,ans,vis[N],dp[N];

struct Node{
    char parentheseSize;
    int idx;
};

signed main() {
    string s;
    cin>>s;
    n = s.length();
    stack<Node> stk;
    int res = 0;
    for(int j=0;j<n;j++){
        if(s[j]=='(' || s[j]=='[' || s[j]=='{') stk.push({s[j],j});
        else{
            if(stk.size()){
                auto [c,idx] = stk.top();
                if(s[j]==')'&&c=='(') {vis[j]=true;vis[idx]=true;;stk.pop();}
                else if(s[j]==']'&&c=='[') {vis[j]=true;vis[idx]=true;stk.pop();}
                else if(s[j]=='}'&&c=='{') {vis[j]=true;vis[idx]=true;res++;stk.pop();}
                else {
                    while(stk.size()) stk.pop();
                    continue;
                }
            }
            else {
                continue;
            }
        }
    }

    for(int i=0;i<n;i++) 
        if(vis[i]) {
            dp[i]=dp[i-1]+1;
            ans = max(dp[i],ans);
        }
    std::cout<<ans<<endl;
    return 0;
}
    