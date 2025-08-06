#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
char ansL,ansR;

struct TreeNode{
    char val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(char val='#'):val(val){}
};

struct RetVal{
    int height;
    int distance;
    char retL = 0 ,retR = 0, ret = 0;
    RetVal(int height,int distance,char retL, char retR, char ret):height(height),distance(distance),retL(retL),retR(retR),ret(ret){}
};

RetVal dfs(TreeNode* head){
    if(head == NULL) {
        return(RetVal(0,0,0,0,0));
    }

    RetVal left = dfs(head->left);
    RetVal right = dfs(head->right);
    int height = max(left.height,right.height)+1;
    int distance = max({left.distance,right.distance,left.height+right.height+1});
    char retL = head->val;
    char retR = head->val;
    char ret = head->val;

    if(left.distance == distance && head->left){
        retL = min(left.retL,left.retR);
        retR = max(left.retL,left.retR);
        
    }
    else if(left.height+right.height+1 == distance && head->left && head->right){
        retL = left.ret;
        
    }
    else if(right.distance == distance && head->right){
        retL = min(right.retL,right.retR);
        retR = max(right.retL,right.retR);
        ret = retL;
    }

    return RetVal(height,distance,retL,retR,ret);
}

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

void dfsCout(TreeNode* head){
    if(head == NULL) return;

    cout << head->val << " ";
    dfsCout(head->left);
    dfsCout(head->right);
}

signed main(){
    int t;cin>>t;
    while(t--){
        TreeNode* head = new TreeNode();
        dfsCin(head);
        
        // dfsCout(head);
        RetVal ans = dfs(head);
        ansL = min(ans.retL,ans.retR);
        ansR = max(ans.retL,ans.retR);
        if(ansL == ansR) cout << ans.distance-1 << ":" << "\n";
        else cout << ans.distance-1 << ":" << ansL << " " << ansR << "\n";
    }
    return 0;
}

/*
Sample Input:
3
A##
ABC##EF#G###D##
ABEH###F#K###
Sample Output:
0:
5:D G
4:H K
*/