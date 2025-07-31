#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m,L,R;

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

TreeNode* cutBST(TreeNode* &head){
    if(!head) return NULL;
    // cur在范围外
    if(head->val < L) return cutBST(head->right);
    else if(head->val > R) return cutBST(head->left);
    
    // cur在范围内
    head->left = cutBST(head->left);
    head->right = cutBST(head->right);
    
    return head;
}

void dfsCout(TreeNode* head){
    if(!head) return;

    cout << head->val << " ";

    dfsCout(head->left);
    dfsCout(head->right);
}

signed main() {
    TreeNode* head = new TreeNode();
    dfsCin(head);
    cin>>L>>R;
    cutBST(head);
    dfsCout(head);
    return 0;
}
    