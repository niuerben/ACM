#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m,a[N],help[N];

int Merge(int l,int r){
    int mid = l+r>>1;
    int ans = 0, sum = 0;
    // 计算跨左右小和
    for(int i=l,j=mid+1;j<=r;j++){
        while(i<=mid && a[j]>=a[i]){
            sum += a[i];
            i++;
        }
        ans+=sum;
    }

    // 归并排序
    int i=l,j=mid+1, k = l;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]) help[k++]=a[i++];
        else help[k++]=a[j++];
    }

    while(i<=mid) help[k++] = a[i++];
    while(j<=r) help[k++] = a[j++];

    for(int i=l;i<=r;i++) a[i]=help[i];

    return ans;
}

int calSum(int l,int r){
    int mid = l+r>>1;
    if(l==r) return 0;
    return calSum(l,mid)+calSum(mid+1,r)+Merge(l,r);
}


signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout << calSum(1,n);
    return 0;
}

/*
Sample Input 1:
6
1 3 5 2 4 6
Sample Output 1:
27
*/