#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m;

struct TreeNode{
    char val;
    int level;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val='#',int level=0):val(val),level(level){}
};
vector<char> ans[N];

void dfsCin(TreeNode*& head){
    char val;
    cin >> val;
    if(val == '#'){
        head = NULL;
        return;
    }
    head->val = val;

    ans[head->level].push_back(val);
    
    head->right = new TreeNode('#',head->level+1);
    dfsCin(head->right);
    head->left = new TreeNode('#',head->level+1);
    dfsCin(head->left);
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

// 层次遍历
void level_order(){
    for(int i=0;ans[i].size();i++){
        reverse(ans[i].begin(),ans[i].end());
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        ans[i].clear();
    }
}

signed main() {
    int t;cin>>t;
    while(t--){
        TreeNode* head = new TreeNode();
        dfsCin(head);
        if(head){
            pre_order(head);cout<<'\n';
            in_order(head);cout<<'\n';
            post_order(head);cout<<'\n';
            level_order();cout<<'\n';
        }
        else{
            for(int i=1;i<=4;i++) puts("NULL");
        }
    }
    return 0;
}
    