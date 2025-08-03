#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,cnt[32];

signed main() {
    int nums[] = {1,1,1,3,3,3,5,4,4,4};
    int m = 3;
    for(int i=0;i<10;i++){
        for(int j=0;j<32;j++){
            // 找出第j位数是否有1
            cnt[j]+=((nums[i]>>j) & 1);
        }
    }
    
    int ans = 0;
    for(int i=0;i<32;i++){
        // cout<<cnt[i]<<" ";
        ans = ans + ((cnt[i]%m!=0)<<i);
    }
    cout << ans;
    return 0;
}
    