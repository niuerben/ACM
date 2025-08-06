#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

struct Node{
    int value;
    Node* left=NULL;
    Node* right=NULL;
    Node(int x):value(x){}
};

// 先序遍历
void pre_order(Node* current){
    stack<Node*> stk;
    stk.push(current);
    while(stk.size()){
        current = stk.top();
        cout << current->value << " ";
        stk.pop();
        // 右子树先入栈
        if(current->right!=NULL){
            stk.push(current->right);
        }
        // 左子树后入栈
        if(current->left!=NULL){
            stk.push(current->left);
        }
    }
}

// 中序遍历
void mid_order(Node* current){
    stack<Node*> stk;
    while(stk.size() || current!=NULL){
        // 左子树进栈
        if(current!=NULL){
            stk.push(current);
            current = current->left;
        }

        // 栈弹出节点，右子树重复1
        else{
            // current恢复至节点
            current = stk.top();
            stk.pop();
            cout << current->value << " ";
            current = current->right;
        }
    }
}

// 后序遍历
void post_order(Node* h){
    stack<Node*> stk;
    stk.push(h);

    while(stk.size()){
        Node* cur = stk.top();
        // 有左树且左树没处理过
        if(cur->left!=NULL && h!=cur->left && h!=cur->right){
            stk.push(cur->left);
        }
        // 有右数且右树没处理过
        else if(cur->left!=NULL && h!=cur->right){
            stk.push(cur->right);
        }
        else{
            cout<< cur->value << " ";
            h = stk.top();
            stk.pop();
        }
    }
}

signed main() {
    // 建树
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);

    cout<<"先序：";
    pre_order(head);cout<<endl;
    cout<<"中序：";
    mid_order(head);cout<<endl;
    cout<<"后序：";
    post_order(head);cout<<endl;
    return 0;
}

/*
Sample Output 1:
先序：1 2 4 5 3 6 7 
中序：4 2 5 1 6 3 7 
后序：1 2 4 5 3 6 7 
*/