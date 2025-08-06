#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

class MyStack{
private:
    queue<int> q;
public:
    void push(int x){
        int t = q.size();
        q.push(x);
        for(int i=1;i<=t;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        q.pop();
    }
    int size(){
        return q.size();
    }
    int front(){
        return q.front();
    }
};

signed main() {
    cin>>n;
    MyStack mst;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        mst.push(x);
    }

    while(mst.size()) {cout<<mst.front()<<" ";mst.pop();}
    return 0;
}

/*
Sample Input 1:
5
1 4 6 7 5
Sample Output 1:
5 7 6 4 1
*/