#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

struct TreeNode{
    char val;
    TreeNode* left=NULL;
    TreeNode* right=NULL;
    TreeNode(int x='#'):val(x){}
};

void dfsCin(TreeNode*& head){
    char val;
    cin >> val;
    if(val == '#'){
        head = NULL;
        return;
    }
    else head->val = val;

    head->left = new TreeNode();
    dfsCin(head->left);
    head->right = new TreeNode();
    dfsCin(head->right);
}

TreeNode* LCA(TreeNode* root,TreeNode* p,TreeNode* q){

    // pq包含关系
    if(root == NULL || root == p || root == q) return root;

    // pq分叉关系
    TreeNode* left = LCA(root->left,p,q);
    TreeNode* right = LCA(root->right,p,q);
    if(left != NULL && right != NULL){
        return root;
    }
    if(left == NULL && right == NULL){
        return NULL;
    }

    return left ? left : right;
}

signed main() {
    TreeNode* head = new TreeNode();
    dfsCin(head);
    TreeNode* p = head->left->left;
    TreeNode* q = head->left->right->left->right;
    cout<<LCA(head,p,q)->val;
    return 0;
}
    