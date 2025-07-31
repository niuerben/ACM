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


// 偷头节点的最大值
static int yes = 0;

// 不偷头节点的最大值
static int no = 0;


// 计算当前节点的偷和不偷各自的最大值
void f(TreeNode* head){
    if(!head){
        yes = 0;
        no = 0;
        return;
    }

    int y = head->val;
    int n = 0;
    // 计算左节点偷和不偷最大值
    f(head->left);
    y += no;
    n += max(yes,no);

    // 计算右节点偷和不偷最大值
    f(head->right);
    y += no;
    n += max(yes,no);

    yes = y;
    no = n;
}

int rob(TreeNode* head){
    f(head);
    return max(yes,no);
}

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

signed main() {
    TreeNode* head = new TreeNode();
    dfsCin(head);
    cout<<rob(head);
    return 0;
}

/*
样例树：
     5
    / \
   /   \
  3     7
 / \   / \
2   4 6   8

Output:
25
*/