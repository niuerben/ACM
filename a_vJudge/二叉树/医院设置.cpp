#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m,ans=inf,vis[N];

struct Node{
    int val;
    vector<int> edge; 
};

struct Node2{
    int nodeIdx;
    int depth;
};

Node nodes[N];


int cal(int cur){
    int res = 0;
    queue<Node2> q;
    q.push({cur,0});
    memset(vis, 0, sizeof vis);

    while(q.size()){
        // 获取当前节点信息
        int curNode = q.front().nodeIdx;
        int d = q.front().depth;
        q.pop();
        int val = nodes[curNode].val;

        // 标记走过节点
        if(vis[curNode]) continue;
        vis[curNode] = true;
        res += d*val;

        // 访问下一个节点
        for(int i=0;i<nodes[curNode].edge.size();i++){
            int v = nodes[curNode].edge[i];
            q.push({v,d+1});
        }
    }

    return res;
}

signed main() {
    cin>>n;
    // 建树
    for(int i=1;i<=n;i++){
        int w,u,v;
        cin>>w>>u>>v;
        nodes[i].val = w;
        if(u){
            nodes[i].edge.push_back(u);
            nodes[u].edge.push_back(i);
        }
        if(v){
            nodes[i].edge.push_back(v);
            nodes[v].edge.push_back(i);
        }
    }

    // 枚举从每个节点出发的距离和
    for(int i=1;i<=n;i++){
        ans = min(ans,cal(i));
    }

    cout << ans;
    return 0;
}