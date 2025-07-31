#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

signed main() {
    cin>>m;
    stack<int> stkGoods;
    stack<int> stkMax;
    while(m--){
        int op;
        cin>>op;
        if(op==0){
            int x;cin>>x;
            stkGoods.push(x);
            if(stkMax.size()) stkMax.push(max(stkMax.top(),x));
            else stkMax.push(x);
        }
        else if(op==1){
            if(stkGoods.empty()) puts("0");
            else {
                stkGoods.pop();
                stkMax.pop();
            }
        }
        else{
            if(stkMax.size()) cout<<stkMax.top()<<'\n';
            else puts("0");
        }
    }
    return 0;
}

/*
本题使用最大栈
Sample Input 1:
13
0 1
0 2
2
0 4
0 2
2
1
2
1
1
2
1
2
Sample Output 1:
2
4
4
1
0

*/