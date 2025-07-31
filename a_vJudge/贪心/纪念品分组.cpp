#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,w,a[N],ans;

signed main() {
    cin>>w;
    cin>>n;
    set<int> st;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    
    while(st.size()){
        auto t = *st.rbegin();
        st.erase(st.end());
        while(st.size() && t+*st.begin()<= w){
            t+=*st.begin();
            st.erase(st.begin());
        }
        ans++;
    }
    cout<<ans;
    return 0;
}
    