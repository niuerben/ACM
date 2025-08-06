#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

struct TreeNode{
    int val;
    TreeNode* left=NULL;
    TreeNode* right=NULL;
    TreeNode(int x=0):val(x){}
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


signed main() {
    TreeNode* head = new TreeNode();
    dfsCin(head);    
    return 0;
}
