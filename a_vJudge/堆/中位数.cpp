#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,a[N];

signed main() {
    cin>>n;
    priority_queue<int,vector<int>,greater<> > q1,q2;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(i&1) q1.push(a[i]);
        else q2.push(a[i]);
    }

    for(int i=1;i<=n/2+1;i++){
        if(q1.top()<q2.top()) {
            cout<<q1.top()<<'\n';
            q1.pop();
        }
        else{
            cout<<q2.top()<<'\n';
            q2.pop();
        }
    }
    return 0;
}
    