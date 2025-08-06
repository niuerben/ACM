#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m,a[N];
map<int,int> mp;

signed main() {
    cin>>n;
    priority_queue<int,vector<int>,greater<> > heap;
    heap.push(1);
    // 计算第2-n个丑数
    for(int i=1;i<=n;i++){
        int t = heap.top();heap.pop();
        while(mp[t]){
            t = heap.top();heap.pop();
        }
        
        mp[t] =true;
        a[i] = t;
        heap.push(t*2);
        heap.push(t*3);
        heap.push(t*5);
    }

    for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
    return 0;
}
    