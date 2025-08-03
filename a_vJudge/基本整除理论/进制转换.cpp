#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;

signed main() {
    
    //  打印二进制
    int n;
    cin>>n;
    string a;
    cin>>a;
    int b = 0;
    for(int i=0;i<a.size();i++){
        if(isdigit(a[i])) b = b*n+a[i]-'0';
        else b = b*n + a[i]-'A'+10;
    }

    char s[32];

    cin>>m;

    string ans;
    while(b){
        char t = b%m;
        if(t<10) t+='0';
        else t+='A'-10;
        ans.push_back(t);
        b/=m;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;

    return 0;
}
    
