#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

struct TreeNode{
    char val;
    TreeNode* left=NULL;
    TreeNode* right=NULL;
    TreeNode(char x='#'):val(x){}
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

// 平衡二叉树：对于每个节点，它的左子树高度-右子树高度的绝对值小于等于1

static bool balance;
// 计算树高
int height(TreeNode* head){
    if(!balance || !head){
        return 0;
    }

    int lh = height(head->left);
    int rh = height(head->right);
    if(abs(lh-rh)>1) balance = false;

    return max(lh,rh)+1;
}

bool check(TreeNode* head){
    balance = true;
    height(head);
    return balance;
}



signed main() {
    TreeNode* head = new TreeNode();
    dfsCin(head);
    if(check(head)) puts("是平衡二叉树");
    else puts("不是平衡二叉树");
    return 0;
}

/*
Sample Input 1:
ABC##EF#G###D##
Sample Output 1:
不是平衡二叉树

Sample Input 2:
ABC##E##D##
Sample Output 2:
是平衡二叉树
*/
    