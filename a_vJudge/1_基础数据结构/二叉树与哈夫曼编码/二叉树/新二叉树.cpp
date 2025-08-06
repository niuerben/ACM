#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=300,inf = 1e9;
int n,m;

struct Node{
    char cur = '*'; 
    char left = '*';
    char right = '*';
};

Node nodes[N];

void dfsCout(char cur){
    if(cur == '*') return;
    // 先序遍历
    cout << cur;
    dfsCout(nodes[cur].left);
    dfsCout(nodes[cur].right);
}

signed main() {
    cin>>n;
    char root;
    // 建树
    for(int i=1;i<=n;i++){
        char cur,u,v;
        cin>>cur>>u>>v;
        if(i==1) root = cur;
        nodes[cur].cur = cur;
        nodes[cur].left = u;
        nodes[cur].right = v;
    }

    dfsCout(root);
    return 0;
}
    