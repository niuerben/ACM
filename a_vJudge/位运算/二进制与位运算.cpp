#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;

signed main() {
    
    //  打印二进制
    int b;
    cin>>b;
    cout << b << endl;
    printf("b 的十进制表示为：%x\n",b);

    char s[32];

    // 将变量由十进制转变为2到35进制
    for(int i=2;i<=35;i++){
        itoa(b,s,i);
        printf("b 的%lld进制表示为：%s\n",i, s);
    }
    return 0;
}
    
