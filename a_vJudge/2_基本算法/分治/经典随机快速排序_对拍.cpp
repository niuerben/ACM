#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10, inf = 1e9;
int n,m,a[N],b[N];

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

void solve(){
    for(int i=1;i<=n;i++) {
        a[i]=rand();
        b[i]=a[i];
    }
    random_sort(1,n);
    sort(b+1,b+1+n);
}

void prove(){
    for(int i=1;i<=n;i++)
        if(a[i]!=b[i]) {
            puts("No");
            for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
            for(int i=1;i<=n;i++) cout<<b[i]<<" \n"[i==n];
            return;
        }
    puts("Yes");
}

signed main() {
    cin>>n;
    solve();
    prove();
    return 0;
}
