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

static bool Search = true;
void in_order(TreeNode* head){
    if(head == NULL){
        return ;
    }
    if(head->left && head->left->val > head->val) Search = false;
    if(head->right && head->right->val < head->val) Search = false;
    in_order(head->left);
    in_order(head->right);
}

signed main() {
    TreeNode* head = new TreeNode();
    dfsCin(head);
    in_order(head);
    if(Search) puts("是搜索二叉树");
    else puts("不是搜索二叉树");
    return 0;
}

/*
Sample Input 1:
5 3 2 -1 -1 4 -1 -1 7 6 -1 -1 8 -1 -1
Sample Output 1:
是搜索二叉树

Sample Input 2:
5 3 4 -1 -1 4 -1 -1 7 6 -1 -1 8 -1 -1
Sample Output 2:
不是搜索二叉树
*/
    