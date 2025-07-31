#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10, inf = 1e9;
int n,m,a[N];

int myPartition(int l,int r, int x){
    int j=l,ix=l;
    // 确保l~j-1区间 a <= x
    for(int i=l;i<=r;i++){
        if(a[i]<=x){
            swap(a[i],a[j]);
            // 记录a[j] == x的位置
            if(a[j]==x) ix = j;
            j++;
        }
    }

    // 确保小区间以x结尾
    swap(a[j-1],a[ix]);
    return j-1;
}

void random_sort(int l,int r){
    if(l>=r) return;

    int x = a[l + rand()%(r-l+1)];
    // cout<<x<<endl;
    int mid = myPartition(l,r,x);
    // <=x 排左边
    random_sort(l,mid-1);
    // >x 排右边
    random_sort(mid+1,r);
}


signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    random_sort(1,n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
    return 0;
}

/*
Sample Input1:
8
3 6 2 7 5 2 4 3
Sample Output1:
2 2 3 3 4 5 6 7
*/