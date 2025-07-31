#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9,mod = 1e9+7;
int n,m,ans;

int qmi(int a,int k){
    int res=1;
    while(k){
        if(k&1) res = res * a % mod;
        k>>=1;
        a = a * a % mod;
    }
    return res;
}

signed main() {
    cin>>n;

    if(n==1) ans = 1;
    else if(n==2) ans =2;
    else if(n%3 == 1) ans = qmi(3,n/3-1) % mod * 4 % mod;
    else if(n%3 == 2) ans = qmi(3,n/3-1) % mod * 2 % mod;
    else ans = qmi(3,n/3); 
    cout<<ans;
    return 0;
}
    
/*
Sample Input 1:
12
Sample Output 1:
81
*/