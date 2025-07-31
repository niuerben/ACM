#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val='#'):val(val){}
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

bool bfsCheck(TreeNode* head){

    // 判断是否出现叶子节点
    bool leaf = false;
    queue<TreeNode*> q;
    while(q.size()){
        TreeNode* cur = q.front();q.pop();

        if(cur->left != NULL){
            q.push(head->left);
        }
        if(cur->right != NULL){
            q.push(head->right);
        }

        if(cur->left == cur->right == NULL) leaf = true;

        // 不存在有右子树无左子树的枝干
        else if(cur->left == NULL && cur->right != NULL) return false;
        
        // 出现叶子后不再允许出现枝干
        else if((cur->left || cur->right) && leaf) return false;
    }
    return true;
}

signed main() {
    TreeNode* head = new TreeNode();
    dfsCin(head);
    bfsCheck(head);

    return 0;
}
    