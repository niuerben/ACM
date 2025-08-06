#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e7+10,mod=1e9+7;
int n,m,k,a[N];


int j_l,j_r;
void my_partition(int l,int r,int x){
    j_l = l, j_r = r;
    for(int i=l;i<=j_r;i++){
        if(a[i]<x){
            swap(a[i],a[j_l]);
            j_l++;
        }
        else if(a[i]>x){
            swap(a[i],a[j_r]);
            j_r--;
            i--;
        }
    }
}

int select_rand(){
    int l=1,r=n;
    for(int i=1;i<=n;i++){
        int x = a[l+rand()%(r-l+1)];
        my_partition(l,r,x);
        if(k < j_l) r = j_l-1;
        else if(k > j_r) l = j_r+1;
        else return x;
    }
}

signed main() {
    cin>>n>>m>>k;
    a[1]=m;
    for(int i=2;i<=n;i++){
        a[i]=(ll)a[i-1]*m%mod;
    }
    cout<<select_rand();
    return 0;
}
    