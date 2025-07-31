#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,a[N],ans;

signed main() {
    cin>>n>>m;
    priority_queue<int,vector<int>,greater<> > heap;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(heap.size()<m) heap.push(a[i]);
        // 小根堆实现后悔
        else if(a[i]>heap.top()) {
            heap.pop();
            heap.push(a[i]);
        }
    }

    while(heap.size()) {
        ans+=heap.top();
        heap.pop();
    }
    cout<<ans;
    return 0;
}
    