#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,a[N],b[N];

// size为数组大小
void f(int cur,int size){
    if(cur>=n){
        if(size == 0) cout<<'\n';
        else{
            for(int i=0;i<size;i++)
                cout<<b[i]<<" \n"[i==size-1];
        }
        return;
    }


    int i = cur;
    int j = cur;
    while(j<=n && a[i]==a[j]) j++;

    f(j,size);
    for(;i<j;i++){
        b[size++] = a[i];
        f(j,size);
    }
}

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+1+n);
    // 递归生成组合数
    f(1,0);

    return 0;
}
    