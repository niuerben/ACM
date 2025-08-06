#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;


int findMax(stack<int> &stk,int size,int &ma){

    if(size==0) return 0;

    int top = stk.top();stk.pop();
    ma = max(top,ma);
    findMax(stk,size-1,ma);
    stk.push(top);
    return ma;
}

int count(stack<int> &stk,int size,int ma){
    if(size==0) return 0;

    int top = stk.top();stk.pop();
    
    int res = (top==ma) + count(stk,size-1,ma);
    stk.push(top);
    return res;

}

void down(stack<int> &stk,int size,int ma,int time){
    // 最大值压入栈底就好了，不补栈
    if(size == 0){
        for(int i=1;i<=time;i++) stk.push(ma);
        return;
    }

    int top = stk.top();stk.pop();

    down(stk,size-1,ma,time);
    if(top != ma) stk.push(top);
}

void Sort(stack<int> &stk,int size){

    while(size){
        int ma = 0;
        ma = findMax(stk,size,ma);
        int time = count(stk,size,ma);

        down(stk,size,ma,time);
        size -= time;
    }
}

signed main() {
    stack<int> stk;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        stk.push(x);
    }

    
    Sort(stk,stk.size());

    while(stk.size()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}

/*
b(9)    max = 6
c(9,6)  time = 2
d(9,6,2)
b(7)    max = 5
c(7,5)  time = 2
d(7,5,2)
b(5)    max = 4
c(5,4)  time = 2
d(5,4,2)
b(3)    max = 3
c(3,3)  time = 2
d(3,3,2)
b(1)    max = 1
c(1,1)  time = 1
d(1,1,1)
*/