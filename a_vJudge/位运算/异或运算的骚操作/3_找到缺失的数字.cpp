#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;

signed main() {
    
    // 3 找到缺失的数字
    int nums[] = {1,2,3,5,4,8,7,9,0};

    int eorSum = 0;
    int eorHas = 0;
    for(int i=0;i<=9;i++) eorSum ^= i;
    for(int i=0;i<9;i++) eorHas ^= nums[i];

    cout<<(eorSum^eorHas);
    
    return 0;
}
    