#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,k,a[N],s[N],help[N];

int merge_sort(int l,int r){
    // 计算跨区和
    int cnt = 0;
    int mid=l+r>>1;
    for(int i=l,j=r;i<=mid;i++){
        while(j>=mid+1 && s[j]-s[i-1]>=k*(j-i+1)) j--;
        cnt+=r-j;
    }

    int i=l, j=mid+1, p=l;
    while(i<=mid && j<=r){
        if(a[i]<a[j]) help[p++]=a[i++];
        else help[p++]=a[j++];
    }

    while(i<=mid) help[p++]=a[i++];
    while(j<=r) help[p++]=a[j++];

    for(int i=l;i<=r;i++)
        a[i]=help[i];
    return cnt;
}

int cal(int l,int r){
    int mid =l+r>>1;
    if(l==r) return  a[l]>=k;

    return cal(l,mid)+cal(mid+1,r)+merge_sort(l,r);
}

signed main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }

    cout<<cal(1,n);
    return 0;
}
    