#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m,x;

vector<int> ans[4];
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

void dfs(TreeNode* &head){
    
    if(x<head->val){
        if(!head->left) {
            head->left = new TreeNode(x);
        }
        else dfs(head->left);
    }
    else{
        if(!head->right){
            head->right = new TreeNode(x);
        }
        else dfs(head->right);
    }

}

// 先序遍历
void pre_order(TreeNode* current){
    if(current==NULL) return;

    ans[1].push_back(current->val);
    pre_order(current->left);
    pre_order(current->right);
}

// 中序遍历
void in_order(TreeNode* current){
    if(current==NULL) return;

    in_order(current->left);
    ans[2].push_back(current->val);
    in_order(current->right);
}
// 后序遍历
void post_order(TreeNode* current){
    if(current==NULL) return;

    post_order(current->left);
    post_order(current->right);
    ans[3].push_back(current->val);
}

signed main() {
    int t;cin>>t;
    while(t--){
        cin>>n;
        TreeNode* head;
        for(int i=1;i<=n;i++){
            cin>>x;
            if(i==1) head = new TreeNode(x);
            else dfs(head);
        }

        pre_order(head);
        in_order(head);
        post_order(head);
        for(int i=1;i<=3;i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" \n"[j==ans[i].size()-1];
            }
            ans[i].clear();
        }
        cout<<'\n';
    }
    return 0;
}
    