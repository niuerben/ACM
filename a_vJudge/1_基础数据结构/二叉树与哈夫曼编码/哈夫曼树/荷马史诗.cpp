#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,k,ans,ans2;
int a[N],b[N];

struct Node{
    int x;
    int d;
    // 优先合并权值最小的，权值相同比较深度
    bool operator<(const Node& other)const{
        return x !=other.x ? x > other.x : d > other.d;
    }
};

signed main() {
    cin>>n>>k;
    priority_queue<Node> q;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        q.push({a[i],0});
    }

    // 哈夫曼编码
    while(q.size() >= k){
        int sum = 0;
        int d = 0;

        // 确保(n-1)%(k-1) == 0，n不足则构造虚节点
        while((q.size()-1) % (k-1) != 0){
            q.push({0,0});
        }
        for(int i=1;i<=k;i++){
            // cout<<b[i]<<" \n"[i==k];
            Node cur = q.top();q.pop();
            b[i] = cur.x;
            d = max(d,cur.d);
            sum += b[i];
        }
        ans2 = max(ans2,d+1);
    
        q.push({sum,d+1});
        ans += sum;
    }
    cout<<ans<<'\n';
    cout << ans2<<'\n';
    return 0;
}
    