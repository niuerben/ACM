#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 70, inf = 1e9;
int n,k,a[N],ans;
int x,now;

long long qread(){
    long long w=1,c,ret;
    while((c=getchar())> '9'||c< '0')
    w=(c=='-'?-1:1); ret=c-'0';
    while((c=getchar())>='0'&&c<='9')
    ret=ret*10+c-'0';
    return ret*w;
}

signed main() {
    scanf("%lld%lld",&n,&k);
    k = 8;
    while(n--){
        x = qread();
        now = 0;
        while(x){
            a[now++] += x % k;
            x /= k;
        }
    }

    for(int i=0;i<=64;i++)
        a[i] %= k;

    for(int i=64;i>=0;i--){
        ans = ans*k + a[i];
        
    }
    cout << ans;
    return 0;
}
    