#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;
int n,m,q,vis[N],t[N],w[N],v[N],dp[N];
vector<pair<int,int>> g;

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i]>>t[i];
        int tt=t[i];
        int k=1;
        while(tt>=k){
            g.push_back({k*v[i],k*w[i]});
            tt-=k;
            k<<=1;
        }
        if(tt>0) {g.push_back({tt*v[i],tt*w[i]});}
    }

    for(auto &[v,w]:g)
        for(int j=m;j>=w;j--)
            dp[j]=max(dp[j],dp[j-w]+v);
    
    cout<<dp[m];
    return 0;
}