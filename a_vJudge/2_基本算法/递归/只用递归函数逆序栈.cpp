#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

// 找到栈底，压出栈底
int bottomOut(stack<int> &stk){
    int top = stk.top();
    stk.pop();

    if(stk.empty()) return top;

    /* 栈                           b1() -> c
         | a |      top = a, last = b2()
         | b |      top = b, last = b3()
         | c |      top = c, last = c
         -----
         
    */
    int last = bottomOut(stk);
    stk.push(top);
    return last;

}

// 逆序栈
void reverse(stack<int> &stk){
    if(stk.size() == 0) return;
    
    /* 栈                    r1()
         | a |      num = c, r2() cba
         | b |      num = b, r3() ba
         | c |      num = a, r4() a
         -----      无
         
    */

    int num = bottomOut(stk);
    reverse(stk);
    stk.push(num);
}


signed main() {
    stack<int> stk;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        stk.push(x);
    }

    // 逆序栈
    reverse(stk);

    // 输出逆序栈
    while(stk.size()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}

/*
只用递归函数，不引入新栈解决逆序栈问题，需要先获得栈底，再将栈底压入栈顶。
获得栈底调用bottomOut函数，逆序栈底调用reverse函数。
bottomOut函数需要收集栈顶，再递归搜索栈底并移除，最后补回栈底
reverse函数需要收集栈底，搜索完所有栈底再将栈底移至栈顶。
*/