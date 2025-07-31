#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,t0;

signed main() {
    int t;cin>>t;
    while(t--){
        string s;
        cin>>n>>t0;
        vector<int> v;
        cin>>s;
        s+=s;
        int last = -1;
        v.push_back(0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') {
                if(i>0 && s[i-1]=='0' && last!=-1) v.push_back(i-last-1);
                last = i;
                if(i>=n) break;
            }
        }
        sort(v.begin(),v.end());

        int sum = 0;
        for(int i=0;i<v.size()-1;i++){
            sum+=max(0ll,v[i]-2*t0);
        }
        sum += max(0ll,v.back()-1-t0);
        cout << sum << '\n';
    }

    
    return 0;
}
    