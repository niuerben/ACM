#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10, inf = 1e9;
int n,m,ans;

struct Node{
    int deadline,profit;
    bool operator<(Node b){
        return deadline==b.deadline ? profit < b.profit : deadline<b.deadline; 
    }
};

Node dp[N];

signed main() {
    
    cin>>n;
    for(int i=1;i<=n;i++){
        int deadline,profit;
        cin>>deadline>>profit;
        dp[i]={deadline,profit};
    }

    sort(dp+1,dp+1+n);
    priority_queue<int,vector<int>,greater<> > min_heap;
    for(int i=1;i<=n;i++){
        // 枚举时间戳
        int d = dp[i].deadline;
        int p = dp[i].profit;

        min_heap.push(p);
        // 小根堆实现后悔
        if(min_heap.size() > d) min_heap.pop();
    }

    while(min_heap.size()){
        ans+=min_heap.top();
        min_heap.pop();
    }
    cout<<ans;
    
    return 0;
}
    