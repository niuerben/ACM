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

int leftMost(TreeNode* cur,int h){
    while(cur!=NULL){
        h++;
        cur = cur->left;
    }
    return h-1;
}

// 计算当前节点子树的节点数
int f(TreeNode* cur,int level,int h){
    
    // 计算左右字节点深度
    int leftH = leftMost(cur->left,level+1);
    int rightH = leftMost(cur->right,level+1);
    
    if(level==h) return 1;
    // 左子树深度等于右子树时
    if(leftH==rightH){
        return (1<<leftH-level) + f(cur->right,level+1,rightH);
    }
    // 左子树更高
    else{
        return f(cur->left,level+1,leftH) + (1<<rightH-level);
    }
}

signed main() {
    TreeNode* head = new TreeNode();
    dfsCin(head);
    int depth = leftMost(head,1);
    cout << f(head,1,depth);
    return 0;
}
    