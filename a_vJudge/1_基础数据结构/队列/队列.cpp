#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

signed main() {
    cin>>m;
    queue<int> q;
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int x;cin>>x;
            q.push(x);
        }
        else if(op==2){
            if(q.size()) q.pop();
            else puts("ERR_CANNOT_POP");
        }
        else if(op==3){
            if(q.size()) cout<<q.front()<<'\n';
            else puts("ERR_CANNOT_QUERY");
        }
        else{
            cout<<q.size()<<'\n';
        }
    }
    return 0;
}

/*
Sample Input 1:
13
1 2
3
4
1 233
3
2
3
2
4
3
2
1 144
3

Sample Output 1:
2
1
2
233
0
ERR_CANNOT_QUERY
ERR_CANNOT_POP
144
*/