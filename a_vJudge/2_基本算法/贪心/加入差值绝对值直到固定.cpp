#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,a[N];

signed main() {
    cin>>n;

    for(int i=1;i<=n;i++) cin>>a[i];

    int gcd = __gcd(a[1],a[2]);
    for(int i=1;i<n;i++) {
        for(int j=i+1;j<=n;j++){
            gcd = __gcd(gcd,__gcd(a[i],a[j]));
        }
    }
    cout<<*max_element(a+1,a+1+n) / gcd;
    return 0;
}

/*
Sample Input 1:
3
2 4 6
Sample Output 1:
3

Sample Input 2:
2
2 7
Sample Output 2:
7
*/