#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;

int qui(int a,int k,int mod){
    int res=1;
    while(k){
        if(k&1) res=res*a%mod;
        k>>=1;
        a=a*a%mod;
    }
    return res;
}

int cal(int k){

    int res=1;
    for(int i=k;i>=1;i--){  
        res=res*i%mod;
    }
    return res;
    
}

signed main() {
    
    int n,k;
    cin>>n>>k;

    int a=n/k;
    int b=n%k;

    if(a==0){
        cout<<0<<endl;
    }else{
        cout<< qui(cal(k)%mod,a%mod,mod)%mod*cal(b)%mod<<endl;
    }


    return 0;
}

