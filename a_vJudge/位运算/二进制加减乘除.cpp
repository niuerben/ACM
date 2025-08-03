#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;

int add(int a,int b){
    int ans = a;
    while(b){
        ans = a^b;
        b = (a&b)<<1;
        a = ans;
    }
    return ans;
}

int neg(int a){
    return add(~a,1);
}

int Minus(int a,int b){
    return add(a,neg(b));
}

int multipy(int a,int b){
    int ans = 0;
    unsigned long long bb = (unsigned long long) b;
    while(bb){
        if(bb&1!=0) ans = add(ans,a);
        bb>>=1;
        a<<=1;
    }

    return ans;
}

int Div(int a,int b){
    int x = a<0 ? neg(a) : a;
    int y = b<0 ? neg(b) : b;

    int ans = 0;
    for(int i=30;i>=0;i=Minus(i,1)){
        if(multipy(y,1<<i) <= x) {
            ans |= (1<<i);
            x = Minus(x,multipy(y,1<<i));
        }
    }
    return a<0 ^ b<0 ? neg(ans) : ans;
}

signed main() {
    int a,b;
    cin>>a>>b;
    cout << add(a,b)<<endl;
    cout << Minus(a,b)<<endl;
    cout << multipy(a,b)<<endl;
    cout << Div(a,b)<<endl;
    return 0;
}
    