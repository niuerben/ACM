#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m,ans;

signed main() {
    cin>>n;
    priority_queue<int,vector<int>,greater<> > heap;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        heap.push(x);
    }
    
    while(heap.size()>1){
        int t1 = heap.top();
        heap.pop();
        int t2 = heap.top();
        heap.pop();
        ans+=t1+t2;
        heap.push(t1+t2);
    }
    cout<<ans;
    return 0;
}
    