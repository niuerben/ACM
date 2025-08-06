#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+10,inf = 1e9;
int n,m,k,a[N];

signed main() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    deque<int> dq;
    for(int i=1;i<=n;i++) dq.push_back(a[i]);
    int offset = 0;
    while(m--){
        int op;cin>>op;
        if(op==1){
            int x;cin>>x;
            offset+=x;
            while(dq.size() && dq.back()+offset>k) dq.pop_back();
        }
        else if(op==2){
            int x;cin>>x;
            offset-=x;
            while(dq.size() && dq.front()+offset<-k) dq.pop_front();
        }
        else cout<<dq.size()<<'\n';
    }
    return 0;
}

/*
此题使用双端队列
Sample Input 1:
3 4 3
-1 1 2
2 3
3
1 5
3
Sample Output 1:
2
1
*/