#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m, mp[N];
string pre,in;

struct TreeNode{
    char val;
    TreeNode* left=NULL;
    TreeNode* right=NULL;
    TreeNode(int x='#'):val(x){}
};


TreeNode* f(int l1,int r1,int l2,int r2){
    if(l1>r1) return NULL;

    TreeNode* head = new TreeNode(pre[l1]);
    // 查找头节点
    if(l1==r1) return head;

    int k = mp[pre[l1]];
    // 寻找左右头节点
    head->left = f(l1+1,l1+k-l2,l2,k-1);
    head->right = f(l1+k-l2+1,r1,k+1,r2);
    
    return head;
}

void dfsCout(TreeNode* head){
    if(head == NULL) return;

    dfsCout(head->left);
    dfsCout(head->right);
    cout<<head->val;
}

signed main() {
    cin>>in>>pre;
    n = in.size();
    for(int i=0;i<n;i++){
        mp[in[i]] = i;
    }

    TreeNode* head = f(0,n-1,0,n-1);
    dfsCout(head);
    return 0;
}
    