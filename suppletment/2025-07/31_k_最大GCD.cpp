#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10, inf = 1e9, mod = 1e9+7;
int n,m,a[N],b[N],c[N];

vector<int> vec[N];

int solve(){
    for(int i=1;i<=n;i++){
        b[i] = a[i] - a[i-1];
    }

    for(int i=vec[a[1]].size()-1;i>=0;i--){
        int fact = vec[a[1]][i];
        vector<int> tmp;
        for(int j=2;j<=n;j++) {
            if(b[j]%fact!=0) tmp.push_back(b[j]);
        }
        
        if(tmp.size()<2) {
            return fact;
            break;
        }
        else if(tmp.size() == 2){
            if((tmp[1]+tmp[0]) % fact == 0) {
                return fact;
                break;
            }
        }
    }

    return 1;
}

signed main() {
    int t;cin>>t;

    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            vec[j].push_back(i);
        }
    }
    while(t--){
        cin>>n;
        int flag = true;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            b[i] = a[i]-a[i-1];
            if(i>1 && a[i]!=a[i-1]) flag = false;
        }
        
        // 若所有数字均相等，则答案可以为无穷大 
        if(flag) {cout<<0<<'\n';continue;}


        // 先考虑全局加的情况
        int g = 0;
        for(int i=2;i<=n;i++) g = abs(__gcd(g,b[i]));

        // 接下来考虑非全局加的情况

        // 讨论 a1 不变的情况
        g = max(g,solve());
        
        // 讨论 an 不变的情况
        reverse(a+1,a+1+n);
        g = max(g,solve());

        cout << g << '\n';
    }
    return 0;
}
    