#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =2e5+10,inf = 1e9;
int n,m,a[N],ans;

signed main() {
    int t;cin>>t;
    while(t--){
        ans = 0;
        cin>>m>>n;
        priority_queue<int,vector<int>,greater<> > heap;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            heap.push(x);
        }
    
        int cur = 0;
        while(heap.size()){
            int t = heap.top();
            heap.pop(); 
            if(t+cur > m) break;
            cur+=t;
            ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
    