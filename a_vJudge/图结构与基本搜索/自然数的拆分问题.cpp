#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;

void dfs(int i,int len,string s){
    if(i==n){
        cout<<s<<endl;
    }

    for(int j=i+len;j<=n;j++){
        char tmp = j-i+'0';
        dfs(j,j-i,s+"+"+tmp); 
    }
}

signed main() {
    cin>>n;

    for(int i=1;i<n;i++){
        dfs(i,i,string(1,i+'0'));
    }

    return 0;
}
    