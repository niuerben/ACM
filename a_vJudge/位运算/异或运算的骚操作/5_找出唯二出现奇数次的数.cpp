#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;

signed main() {
    
    // 5 找出唯二出现奇数次的数
    int nums[] = {1,1,3,3,4,6,5,5,5,5};

    int eorSum = 0;
    for(int i=0;i<10;i++) eorSum^=nums[i];

    // 找出最右侧的1（BK算法）
    int rightOne = eorSum&(-eorSum);
    int eor2 = 0;
    for(int i=0;i<10;i++){
        if((nums[i] & rightOne) != 0){
            eor2^=nums[i];
        }
    }

    int a = eor2;
    int b = eorSum^eor2;
    if(a>b) swap(a,b);
    cout<<a<<" "<<b;

    return 0;
}
    