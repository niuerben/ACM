#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 210, inf = 1e9, mod = 1e9+7;
int n,m,vis[N];

// 纯字符串+贪心
vector<string> str;
string ans;
void dfs(string curStr){
    if(curStr.size() > ans.size()) ans = curStr;

    for(int j=1;j<=n;j++){
        if(vis[j]==2) continue;
        
        // 贪心地匹配字符串
        int len = curStr.size();
        for(int k=len-1;k>=0;k--){
            if(curStr[k]==str[j][0]){
                // substr字符串切片,从索引k开始
                // 贪心地匹配两个字符串的最小重合部分
                if(curStr.substr(k)==str[j].substr(0,len-k)) {
                    vis[j]++;
                    dfs(curStr+str[j].substr(len-k));
                    vis[j]--;
                }
            }
        }
        
    }
}


signed main() {
    cin>>n;
    str.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>str[i];
    }
    cin>>str[0];

    dfs(str[0]);
    cout<<ans.size();
    return 0;
}
    