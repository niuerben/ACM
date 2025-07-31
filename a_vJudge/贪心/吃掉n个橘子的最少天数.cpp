#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,ans;

int getMin(int n){
    if(n<=1) return n;
    int x = n%2+1+getMin(n/2);
    int y = n%3+1+getMin(n/3);
    return ans = min(x,y);
}

signed main() {
    cin>>n;
    cout<<getMin(n)<<endl;
    return 0;
}
    