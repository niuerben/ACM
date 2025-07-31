#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x){}
};

// 递归序
void recursion_order(TreeNode *current){
    if(current==NULL) return;

    cout << current->val << " ";
    recursion_order(current->left);
    cout << current->val << " ";
    recursion_order(current->right);
    cout << current->val << " ";
}

// 先序遍历
void pre_order(TreeNode* current){
    if(current==NULL) return;

    cout << current->val << " ";
    pre_order(current->left);
    pre_order(current->right);
}

// 中序遍历
void in_order(TreeNode* current){
    if(current==NULL) return;

    in_order(current->left);
    cout << current->val << " ";
    in_order(current->right);
}
// 后序遍历
void post_order(TreeNode* current){
    if(current==NULL) return;

    post_order(current->left);
    post_order(current->right);
    cout << current->val << " ";
}

signed main() {
    // 建树
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);

    cout<<"递归序：";
    recursion_order(head);cout<<endl;
    cout<<"先序：";
    pre_order(head);cout<<endl;
    cout<<"中序：";
    in_order(head);cout<<endl;
    cout<<"后序：";
    post_order(head);cout<<endl;
    return 0;
}

/*
Sample Output 1:
递归序：1 2 4 4 4 2 5 5 5 2 1 3 6 6 6 3 7 7 7 3 1 
先序：1 2 4 5 3 6 7 
中序：4 2 5 1 6 3 7 
后序：1 2 4 5 3 6 7 
*/