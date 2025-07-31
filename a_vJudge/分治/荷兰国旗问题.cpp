#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10, inf = 1e9;
int n,m,a[N];

// 利用全局变量“返回两个值”
int j_l,j_r;
void myPartition(int l,int r, int x){
    j_l = l,j_r = r;
    for(int i=l;i<=r;i++){
        // 划分<x区域
        if(a[i]<x){
            swap(a[i],a[j_l]);
            j_l++;
        }
        // 划分>x区域
        else if(a[i]>x){
            swap(a[i],a[j_r]);
            j_r--;
            i--;
        }
    }
}

void random_sort(int l,int r){
    if(l>=r) return;

    int x = a[l + rand()%(r-l+1)];
    myPartition(l,r,x);
    // <=x 排左边
    random_sort(l,j_l-1);
    // >x 排右边
    random_sort(j_r,r);
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
    