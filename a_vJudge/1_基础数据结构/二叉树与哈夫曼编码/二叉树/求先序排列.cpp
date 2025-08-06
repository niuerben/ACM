#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m, mp[N];
string post,in;

struct TreeNode{
    char val;
    TreeNode* left=NULL;
    TreeNode* right=NULL;
    TreeNode(int x='#'):val(x){}
};


TreeNode* f(int l1,int r1,int l2,int r2){
    if(l1>r1) return NULL;

    TreeNode* head = new TreeNode(post[r1]);
    if(l1==r1) return head;
    
    // 查找中序排列的头节点
    int k = mp[post[r1]];
    
    // 寻找左右头节点
    head->left = f(l1,l1+k-l2-1,l2,k-1);
    head->right = f(l1+k-l2,r1-1,k+1,r2);
    
    return head;
}

void dfsCout(TreeNode* head){
    if(head == NULL) return;

    cout<<head->val;
    dfsCout(head->left);
    dfsCout(head->right);
}

signed main() {
    // 输入中序排列和后序排列
    cin>>in>>post;
    n = in.size();

    // 存储节点映射中序排列位置的哈希表
    for(int i=0;i<n;i++){
        mp[in[i]] = i;
    }

    // 查找头节点
    TreeNode* head = f(0,n-1,0,n-1);
    
    // dfs输出先序排列
    dfsCout(head);
    return 0;
}
    