#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;
int f[45];

int fib(int n){
    if(f[n]) return f[n];
    if(n == 0) return f[n] = 1;
    if(n == 1) return f[n] = 1;

    /*
            n
           / \
        n-1   n-2
        / \
     n-2   n-3
     ...
     2
    / \
    1 0
    */
 
    return f[n] = fib(n-1) + fib(n-2);
}

signed main() {
    cin>>n;
    
    cout<<fib(n);
    return 0;
}
    