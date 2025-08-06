#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,inf = 1e9;
int n,m,k,a[N];

int j_l,j_r;

void myPartiton(int l,int r,int x){
    j_l = l;
    j_r = r;

    for(int i=l;i<=r;i++){
        // 扩充左区间
        if(a[i]<x){
            swap(a[i],a[j_l]);
            j_l++;
        }
        // 扩充右区间
        else if(a[i]>x){
            swap(a[i],a[j_r]);
            j_r--;
            i--;
        }
    }
}

int select(){
    int l=1,r=n;
    for(int i=1;i<=n;i++){
        int x = a[l+rand()%(r-l+1)];
        myPartiton(l,r,x);
        // 确定k的分区
        if(n-k<j_l) r = j_l-1;
        else if(n-k>j_r) l = j_r+1;
        else return x;
    }
}

signed main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<select();
    return 0;
}
    