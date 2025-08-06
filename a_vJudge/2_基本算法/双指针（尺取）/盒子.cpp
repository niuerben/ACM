#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;
int n,m,a[N],b[N],p2[N],sum,cur,cnt;

int qmi(int a,int k,int p){
    int res=1;
    while(k){
        if(k&1) res = res * a % p;
        k>>=1;
        a = a * a %p;
    }
    return res;
}

signed main(){
    int n;cin>>n;

    p2[0] = 1;
    for(int i=1;i<=60;i++) p2[i]=p2[i-1]*2;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[(int)log2(a[i])]++;
        sum+=a[i];
    }

    // int ts = 0;
    // for(int i=0;i<=5;i++){    
    //     cout<<b[i]<<" \n"[i==5];
    // }
    // for(int i=0;i<=5;i++){
    //     ts+=b[i]*p2[i];
    //     cout<<ts<<" \n"[i==5];
    // }

    for(int i=60;i>=0;i--){
        if(sum-p2[i]*b[i] < p2[i]*b[i]/2){
            
        }
        cnt+=max(0ll,sum-p2[i]*b[i]);
    }

    cout<<cnt;
    return 0;
}

