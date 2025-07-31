#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
char a[N];
int n,m;

// signed main() {
//     string s;
//     cin>>s>>n;
//     int len = s.size();
//     // 寻找包含n的最小倍增纸带
//     while(len<n) len*=2;

//     // 寻找n映射至1~s.size()的下标
//     while(n>s.size()){
//         // 折叠临界点直接折叠
//         if(n==len/2+1) n=len/2;
//         // n大于半长+1直接平移
//         else if(n>len/2+1) n = n - len/2 - 1;
//         // n太小时折叠长度
//         else len/=2;
//     }
//     cout<<s[n-1];
//     return 0;
// }

/*
Sample Input 1:
COW 8
Sample Output 1:
C
*/

// 创建折纸序列
// signed main() {
//     string s;
//     cin>>s>>n;
//     int len = s.size();
//     for(int i=1;i<=s.size();i++) a[i]=s[i-1];
//     // 寻找包含n的最小倍增折纸
//     while(len<n) {
//         for(int i=len+1;i<=len*2;i++) a[i] = a[2*len+1-i];
//         len*=2;
//     }
//     for(int i=1;i<=len;i++) cout<<a[i];
//     return 0;
// }

/*
Sample Input 1:
HAO- 8
Sample Output 1:
HAO--OAH
*/
    
// signed main() {
//     string s;
//     cin>>s>>n;
//     int len = s.size();
//     // 寻找包含n的最小倍增纸带
//     while(len<n) len*=2;

//     // 寻找n映射至1~s.size()的下标
//     while(n>s.size()){
//         if(n>len/2) n = len+1-n;
//         // n太小时折叠长度
//         else len/=2;
//     }
//     cout<<s[n-1];
//     return 0;
// }
