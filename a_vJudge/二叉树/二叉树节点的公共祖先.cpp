#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

signed main() {
    while(cin>>n>>m){

        while(n!=m){
            if(n>m){
                n/=2;
            }
            else m/=2;
        }
        cout<<n<<'\n';
    }
    return 0;
}
