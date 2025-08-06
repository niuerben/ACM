#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

signed main() {
    cin>>n;
    vector<string> s(n+1);
    for(int i=1;i<=n;i++) cin>>s[i];

    sort(s.begin()+1,s.end(),[](string a,string b){
        string t1 = a+b;
        string t2 = b+a;
        return t1<t2;
    });

    string ans;
    for(int i=1;i<=n;i++) ans+=s[i];
    cout<<ans; 
    return 0;
}

/*
Sample Input 1:
3
ab bc ef
Sample Output 1:
abbced

Sample Input 1:
3
ab a ef
Sample Output 1:
aabef
*/