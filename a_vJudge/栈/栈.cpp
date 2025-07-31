#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

signed main() {
    int t;cin>>t;
    while(t--){
        cin>>m;
        while(m--){
            stack<int> st;
            string op;
            cin>>op;
            if(op=="push") {int x;cin>>x;st.push(x);}
            else if(op=="query") {
                if(st.size()) cout<<st.top()<<"\n";
                else puts("Anguei!");
            }
            else if(op=="size") cout<<st.size()<<"\n";
            else if(op=="pop") {
                if(st.size()) st.pop();
                else puts("Empty");
            }
        }

    }
    return 0;
}

