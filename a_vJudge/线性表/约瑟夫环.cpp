#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll N = 2025,inf=0x3f3f3f3f;
ll n,m,ans,res,dd,a[N][N],dp[N][N];


int main(){
    cin>>n>>m;

    list<int> node;
    for(int i=1;i<=n;i++) node.push_back(i); 

    auto it = node.begin();
    while(node.size()){
        
        for(int j=1;j<m;j++){
            it++;
            if (it == node.end()) it = node.begin();
        }
        if(node.size() == 1) cout<<*it<<" ";
        auto next = ++it;
        if(next == node.end()) next = node.begin();
        node.erase(--it);
        it = next;
    }


    return 0;
}