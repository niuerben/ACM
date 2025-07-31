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

vector<TreeNode*> nq(N);
int iq[N];
void bfs(TreeNode*& head){
    int l=0, r=0;
    nq[r] = head;
    iq[r++] = 1;
    while(l<r){
        int size = r-l;

        // 计算当前层的最大特殊宽度
        ans = max(ans,iq[r-1]-iq[l]+1);
        // 扩充队列
        for(int i=0;i<size;i++){
            TreeNode* cur = nq[l];
            int id = iq[l++];
            if(cur->left){
                nq[r] = cur->left;
                iq[r++] = 2*id;
            }
            if(cur->right){
                nq[r] = cur->right;
                iq[r++] = 2*id+1;
            }
        }

    }
}

signed main(){
    TreeNode* head = new TreeNode();
    dfsCin(head);
    bfs(head);
    cout<<ans;
    return 0;
}

/*
Sample Input:
ABCD00E000FG00H0I00
Sample Output:
8
*/