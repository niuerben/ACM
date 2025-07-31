#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,k,a[N],ans,vis[N];

struct Node{
    int a,i;
    bool operator>(const Node b){
        return a==b.a ? i < b.i : a < b.a;
    }
};

signed main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];

    priority_queue<Node,vector<Node>,greater<> > heap;
    for(int i=1;i<=n;i++) {
        int l=a[i-1];
        int r=a[i+1];
        heap.push({a[i],i});
    }

    for(int i=1;i<=k;i++){
        Node t = heap.top();heap.pop();
        if(vis[t.i]) continue;
        
        int l=0,r=0;
        if(!vis[t.i-1]) l = a[t.i-1];
        if(!vis[t.i+1]) r = a[t.i+1];
        if(t.a < l+r) continue;

        ans+=t.a;
        vis[t.i] = true;
        vis[t.i-1] = true;
        vis[t.i+1] = true;
        heap.push({l+r-t.a,t.i});
    }
    cout<<ans;
    return 0;
}
    