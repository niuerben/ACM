#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;
int n,m,q,vis[N],t[N],w[N],v[N],dp[N];
vector<pair<int,int>> g;

int shh,smm,ehh,enn;
signed main(){
    scanf("%d:%d %d:%d",&shh,&smm,&ehh,&enn);
    cin>>n;
    m = (ehh*60+enn)-(shh*60+smm);
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i]>>t[i];
        if(t[i]==0) t[i]=1e9;
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