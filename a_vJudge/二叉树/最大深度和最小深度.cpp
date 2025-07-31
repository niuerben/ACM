#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int ans;

struct TreeNode{
    char val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(char val='0'):val(val){}
};


void dfsCin(TreeNode*& head){
    char val;
    cin >> val;
    if(val == '0'){
        head = NULL;
        return;
    }
    else head->val = val;

    head->left = new TreeNode();
    dfsCin(head->left);
    head->right = new TreeNode();
    dfsCin(head->right);
}

int maxDepth(TreeNode* root){
    if(!root) return 0;
    return max(maxDepth(root->left),maxDepth(root->right)) + 1;
}

int minDepth(TreeNode* root){
    if(!root) return 0;
    return min(minDepth(root->left),minDepth(root->right))+1;
}

signed main(){
    TreeNode* head = new TreeNode();
    // 建树
    dfsCin(head);
    // 搜索最大深度
    cout << maxDepth(head) << endl;
    // 搜索最小深度
    cout << minDepth(head) << endl;
    return 0;
}

/*
Sample Input:
ABCD00E000FG00H0I00
Sample Output:
8
*/