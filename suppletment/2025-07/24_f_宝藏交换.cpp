#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+10, inf = 1e9, mod = 1e9+7;
int n,k,c,ans;

struct Node{
    int v;
    int idx;
};

bool cmp(Node a,Node b){
    return a.v-c*a.idx > b.v-c*b.idx;
}
Node a[N];

signed main() {
    cin>>n>>k>>c;
    // 考虑希望最终数组的前 k 个元素为初始数组子序列 ax_1, ax_2, ... ax_k 所需要的最小交换次数
    // 容易发现所需要的交换次数 num = ∑( x_i - i)  
    for(int i=1;i<=n;i++){
        cin>>a[i].v;
        a[i].idx = i;
    }    

    // 所有数字按照ai−c*i排序
    sort(a+1,a+1+n,cmp);

    // ∑(a_i - num * c)
    for(int i=1;i<=k;i++){
        ans +=a[i].v-(a[i].idx-i)*c;
    }
    cout<<ans;
    return 0;
}
    