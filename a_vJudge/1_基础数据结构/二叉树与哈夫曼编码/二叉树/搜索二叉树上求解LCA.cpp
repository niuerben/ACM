#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

struct TreeNode{
    int val;
    TreeNode* left=NULL;
    TreeNode* right=NULL;
    TreeNode(int x=-1):val(x){}
};

void dfsCin(TreeNode*& head){
    int val;
    cin >> val;
    if(val == -1){
        head = NULL;
        return;
    }
    else head->val = val;

    head->left = new TreeNode();
    dfsCin(head->left);
    head->right = new TreeNode();
    dfsCin(head->right);
}

// 搜索二叉树求解leastCommonAncestor
TreeNode* LCA(TreeNode* root,int p,int q){

    while(root->val != p && root->val != q){
        if(min(p,q) < root->val && root->val < max(p,q)){
            break;
        }
        root = root->val < min(p,q) ? root->right : root->left;
    }
    return root;
}

// 建立搜索二叉树
void build(TreeNode* root, int x){
    while(true){
        if(x < root->val) {
            if(root->left == NULL) {root->left = new TreeNode(x);break;}
            else root = root->left;
        }
        else if(x > root->val) {
            if(root->right == NULL) {root->right = new TreeNode(x);break;}
            else root = root->right;
        }
    }
}

signed main() {
    cin>>n;
    TreeNode* head = new TreeNode();
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        build(head,x);
    }

    int p,q;
    cin>>p>>q;
    cout<<LCA(head, p,q)->val;
    return 0;
}
    