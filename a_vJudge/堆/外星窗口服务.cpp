#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

signed main() {
    cin>>n;
    priority_queue<int,vector<int>,greater<> > heap;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            int x;cin>>x;
            heap.push(x);
        }
        else{
            cout<<heap.top()<<'\n';
            heap.pop();
        }
    }
    return 0;
}
    