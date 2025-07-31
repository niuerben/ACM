#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,a[N];

int Max(int arr[],int l,int r){
    if(l==r) return arr[l];

    int lMax = Max(arr,l,l+r>>1);
    int rMax = Max(arr,(l+r>>1)+1,r);
    return max(lMax,rMax);
}

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    cout << Max(a,1,n);     // f(1,n)最先压入栈底
    return 0;
}

/*
Sample Input 1:
5
1 2 3 4 5
Sample Output 1:
5

Sample Input 2:
5
23 12 34 56 78
Sample Output 2:
78
*/

/*
Master公式
所有子问题规模相同的递归问题才能使用Master公式，T(n) = a*T(n/b) + O(n^c)
log(b,a) < c，复杂度为 O(n^c) eg: T(n) = 2*(T/2) + O(n^2)，复杂度为 O(n^2)
log(b,a) == c，复杂度为 O(n^c*log(b,a)) eg: T(n) = 2*(T/2) + O(n)，复杂度为 O(nlogn)
log(b,a) > c，复杂度为 O(n^(log(b,a))) eg: T(n) = 2*(T*2/3) + O(1)，复杂度为 O(n^(log(3/2,2)))
特别地，T(n) = 2*T(n/2) + O(nlogn) 复杂度为 O(n*log(n)^2)
*/