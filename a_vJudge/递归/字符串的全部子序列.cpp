#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;
string s;
set<string> mp;

void f(int i,string t){
    if(i==n) {
        mp.insert(t);
        return;
    }

    f(i+1,t+s[i]);
    f(i+1,t);
}

signed main() {
    cin>>s;
    n = s.size();

    f(0,"");
    
    for(auto str:mp) cout<<"\""<<str<<"\",";
    return 0;
}
    