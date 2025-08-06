#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10,inf = 1e9;
int n,m,a[N][N];

void arrange(int l,int r,int h){
    int mid = l+r>>1;
    if(l==r) return;

    // 子问题：寻找左上角和右上角进行安排
    arrange(l,mid,h/2);
    arrange(mid+1,r,h/2);

    // 把左上角的安排填充到右下角,把右上角的安排填充到左下角
    for(int i=1;i<=h;i++){
        for(int j=l;j<=r;j++){
            a[2*h+1-i][2*mid+1-j] = a[i][j]; 
        }
    }

}

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) a[1][i]=i;
    arrange(1,n,n/2);
    for(int i=1;i<=n;i++)
        for(int j=2;j<=n;j++)
            cout<<a[i][j]<<" \n"[j==n];
    return 0;
}

/*
Sample Input 1:
8
Sample Output 1:
2 3 4 5 6 7 8
1 4 3 6 5 8 7
4 1 2 7 8 5 6
3 2 1 8 7 6 5
6 7 8 1 2 3 4
5 8 7 2 1 4 3
8 5 6 3 4 1 2
7 6 5 4 3 2 1
*/
    