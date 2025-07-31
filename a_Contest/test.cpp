#include<bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int,int> pii;

signed main() {

    int x,k;
    cin>>x>>k;
    if(x==1){
        cout<<1<<endl;
        return 0;
    }

    int res=x;
    vector<pii> a;
    map<int,int> mp;
    int cnt=0;
    mp[x]=1;
    while(res!=1){
        cnt++;
        res=(int)sqrt(res);
        if(cnt>k) break;
        if(!mp[res]){
            mp[res]++;
            if(res!=1) a.push_back({res,k-cnt+1});
            else a.push_back({res,1});
        }
    }

    for(int i=0;i<a.size();i++){
        int y=a[i].first;
        int cur=y;
        int tol=0;
        if(y==1) continue;
        while(y<=1e9){
            tol++;
            y*=y;
            if(mp[y]){
                // res+=tol;
                mp[cur]=-1;
                break;
            }
        }
    }
    int ans=0;
    for(int i=0;i<a.size();i++){
        if(mp[a[i].first]&&mp[a[i].first]!=-1){
            ans+=a[i].second;
            // cout<<a[i].first<<' '<<a[i].second<<endl;
        }
        if(mp[a[i].first]==-1) ans++;
    }
    cout<<ans+k+1<<endl;

    return 0;
} 