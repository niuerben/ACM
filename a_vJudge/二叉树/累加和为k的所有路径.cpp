#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,inf = 1e9;
int n,m,target,ans,idx;

struct TreeNode{
    int val = 0;
    int left= -1;
    int right= -1;
};

TreeNode treenode[N];

void build(){

    for(int i=1;i<=n;i++){
        int val, left,right;
        cin>>val>>treenode[i].left>>treenode[i].right;
        treenode[i].val = val;
    }
}

void calAdd(int head,int sum){
    if(treenode[head].left == -1 && treenode[head].right == -1){
        if(sum == target) ans++;
        return;
    }
    
    int left = treenode[head].left;
    int right = treenode[head].right;
    if(left != -1) calAdd(left,sum+treenode[left].val);
    if(right != -1) calAdd(right,sum+treenode[right].val);
}

signed main() {
    cin>>n;
    build();
    cin>>target;
    calAdd(1,treenode[1].val);
    cout<<ans;
    return 0;
}
    