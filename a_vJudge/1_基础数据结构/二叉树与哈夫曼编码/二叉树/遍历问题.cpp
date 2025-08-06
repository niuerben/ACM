#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10, inf = 1e9;
int n,m,mp[N];
long long ans;
string pre,post;

void f(int l1,int r1,int l2,int r2){

    if(l1>=r1) return;
    else if(l1+1==r1 && pre[l1]==post[r2] && pre[l2]==post[r1]) {ans++;return;}
    
    // 查找后序排列的左子节点
    int find = mp[pre[l1+1]];

    // 只有一个子节点，先记录单子节点，再继续查找子节点的单子结点
    if(find == r2-1){
        ans++;
        f(l1+1,r1,l2,r2-1);
    }
    // 有两个子节点就分别查找连个子节点的单子节点
    else {
        f(l1+1,l1+1+find-l2,l2,find);
        f(l1+find-l2+2,r1,find+1,r2-1);
    }
}

int main() {
    cin>>pre;
    cin>>post;
    n = pre.size();
    // 节点映射后序排列的位置
    for(int i=0;i<n;i++){
        mp[post[i]] = i;
    }
    // 查找整棵树的单子结点
    f(0,n-1,0,n-1);
    cout << (1<<ans);
    return 0;
}