#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10,inf = 1e9;
int n,m;

struct Node{
    int left;
    int right;
};

Node nodes[N];

int maxDepth(int cur){
    if(cur==0) return 0;
    else return max(maxDepth(nodes[cur].left),maxDepth(nodes[cur].right))+1;
}

signed main() {
    cin>>n;
    // 建树
    for(int i=1;i<n;i++){
        cin>>nodes[i].left>>nodes[i].right;
    }

    cout << maxDepth(1) << endl;

    return 0;
}
    