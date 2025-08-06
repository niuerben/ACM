#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
char ansL,ansR;

struct TreeNode{
    char val;
    int depth;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(char val='0',int depth=0):val(val),depth(depth){}
};

vector<char> ans[N];


priority_queue<TreeNode> heap;

void dfsCin(TreeNode*& head){
    char val;
    cin >> val;
    if(val == '0'){
        head = NULL;
        return;
    }
    else head->val = val;

    ans[head->depth].push_back(head->val);
    head->left = new TreeNode(0,head->depth+1);
    dfsCin(head->left);
    head->right = new TreeNode('0',head->depth+1);
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
        for(int i=0;ans[i].size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j];
            }
            ans[i].clear();
        }
        cout<<endl;
        delete head;
    }
    return 0;
}

/*
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

map<int,int> mp;
vector<int> hash[N];
queue<TreeNode*> q;

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

void bfsCout(TreeNode*& head){
    q.push(head);
    mp[head->val] = 0;
    while(q.size()){
        TreeNode* t = q.front();
        q.pop();
        cout<<t->val<<" ";
        if(t->left){
            q.push(t->left);
            mp[t->left->val] = mp[t->val]+1;
        }
        if(t->right){
            q.push(t->right);
            mp[t->right->val] = mp[t->val]+1;
        }
    }
}

signed main(){
    TreeNode* head = new TreeNode();
    dfsCin(head);
    bfsCout(head);
    
    return 0;
}
*/

