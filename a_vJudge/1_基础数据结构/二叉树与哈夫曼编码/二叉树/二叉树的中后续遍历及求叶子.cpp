#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n,inord[N],postord[N];

int getMin(int ind[],int pod[],int len){
    if(len==0) return 1e9;
    if(len==1) return ind[1];
    int rt;
    for(rt=1;ind[rt]!=pod[len];rt++);
    return min(getMin(ind,pod,rt-1),getMin(ind+rt,pod+rt-1,len-rt));
}

signed main(){
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>inord[i];
        for(int i=1;i<=n;i++) cin>>postord[i];
        cout << getMin(inord,postord,n) << '\n';
    }
    return 0;
}