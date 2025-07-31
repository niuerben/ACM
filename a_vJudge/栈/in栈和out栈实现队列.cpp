#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

class Myqueue{
private:
    stack<int> in,out;
public:
    void push(int x){
        in.push(x);
    }
    void pop(){
        if(out.size()){out.pop();return;}
        if(in.size()){out.push(in.top());in.pop();return;}
    }
    int top(){
        if(out.empty()) while(in.size()){out.push(in.top());in.pop();}
        return out.top();
    }
    int size(){
        return in.size()+out.size();
    }
    

};

signed main() {
    cin>>n;
    Myqueue mq;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        mq.push(x);
    }

    while(mq.size()){cout<<mq.top()<<" ";mq.pop();}

    return 0;
}

/*
Sample Input 1:
5
1 4 6 7 5
Sample Output 1:
1 4 6 7 5
*/