#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;

signed main() {
    
    int nums[] = {1,1,3,3,4,5,5,5,5};

    int eorSum = 0;
    for(int i=0;i<9;i++) eorSum^=nums[i];
    cout<<eorSum;
    return 0;
}
    