#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

struct Node{
    char value;
    Node* left=NULL;
    Node* right=NULL;
    Node(char x='0'):value(x){}
};


// 后序遍历（非递归）
void post_order(Node* root) {
    if (!root) return;

    stack<Node*> stk;
    Node* lastVisited = nullptr;
    Node* cur = root;

    while (!stk.empty() || cur) {
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }
        Node* topNode = stk.top();
        // 如果右子树存在且没有被访问过
        if (topNode->right && lastVisited != topNode->right) {
            cur = topNode->right;
        } else {
            cout << topNode->value;
            lastVisited = topNode;
            stk.pop();
        }
    }
}


void dfsCin(Node*& head){
    char value;
    cin >> value;
    if(value == '0'){
        head = NULL;
        return;
    }
    else head->value = value;
    head->left = new Node();
    dfsCin(head->left);
    head->right = new Node();
    dfsCin(head->right);
}



signed main() {
    int t;
    cin>>t;
    getchar();
    while(t--){
        // 建树
        Node* head = new Node();
        dfsCin(head);;
        post_order(head);cout<<endl;
        delete head;
    }
    return 0;
}

