#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

signed main() {
    int n;
    cin>>n;
    stack<int> stkData;
    stack<int> stkMin;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        stkData.push(x);
        if(stkMin.size() ){stkMin.push(min(stkMin.top(),x));}
        else stkMin.push(x);
    }

    while(stkData.size()){
        printf("当前栈顶为：%d，栈内最小值为：%d\n",stkData.top(),stkMin.top());
        stkData.pop();
        stkMin.pop();
    }
    return 0;
}
    
/*
Sample Input 1:
5
3 5 2 7 4
Sample Output 1:
当前栈顶为：4，栈内最小值为：2
当前栈顶为：7，栈内最小值为：2
当前栈顶为：2，栈内最小值为：2
当前栈顶为：5，栈内最小值为：3
当前栈顶为：3，栈内最小值为：3
*/