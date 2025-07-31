#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

signed main() {
    string seq;
    string ans;
    cin>>seq;
    n = seq.size();
    stack<char> stk;
    for(int i=0;i<n;i++){
        if(seq[i]=='(') {
            ans+="(";
            stk.push('(');
        }
        else{
            if(stk.size()){
                ans+=")";
                stk.pop();
            }
            else{
                ans = ans + "()";
            }

        }
    }
    while(stk.size()){
        ans+=")";
        stk.pop();
    }
    cout<<ans;
    return 0;
}
    