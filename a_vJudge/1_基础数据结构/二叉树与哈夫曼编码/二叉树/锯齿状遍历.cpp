#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
char ansL,ansR;

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

vector<TreeNode*> q(N);
void bfs(TreeNode*& head){
    int l=0, r=0;
    q[r++] = head;
    bool reverse = false;
    while(l<r){
        int size = r-l;
        // 收集size个数据
        for(int i = reverse ? r - 1 : l, j = reverse ? -1 : 1, k = 0; k < size; i += j, k++){
            cout<<q[i]->val<<" ";
        }

        // 扩充队列
        for(int i=0;i<size;i++){
            TreeNode* cur = q[l++];
            if(cur->left) q[r++]=cur->left;
            if(cur->right) q[r++]=cur->right;
        }

        // 翻转
        reverse = !reverse;
    }
}

signed main(){
    TreeNode* head = new TreeNode();
    dfsCin(head);
    bfs(head);
    return 0;
}

/*
Sample Input:
ABCD00E000FG00H0I00
Sample Output:
A F B C G H I E D 
*/