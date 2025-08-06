#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;

// 时间复杂度O(n+m)+O(m*log(m))

/*
最小生成树
Prim算法(不算常用)
1 解锁的点的集合叫done(普通集合)、解锁的边的集合叫heap(小根堆)。done和heap都为空。
2 可从任意点开始，开始点加入到done，开始点的所有边加入到heap
3 从heap中弹出权值最小的边e，查看边e所去往的点x
    A.如果x已经在set中，边e舍弃，重复步骤3
    B.如果x不在set中，边e属于最小生成树，把x加入set，重复步骤3
4 当heap为空，最小生成树的也就得到了
*/

int ans,n,m,done[N];
struct Edge{int to,w;
bool operator < (const Edge &other) const {return w>other.w;}
};
Edge edge[N];
vector<Edge> g[N];
void prim(){
    priority_queue<Edge> q;
    q.push({1,0});
    done[1]=true;
    int cnt = 0;
    while(q.size()){
        auto [u,w] = q.top();q.pop();
        cnt++;
        for(auto &[v,w]:g[u]){
            if(done[v]) continue;
            q.push({v,w});
            ans+=w;
        }
    }
    if(cnt==n) cout<<ans<<"\n";
    else puts("orz");
}

signed main() {
    
    return 0;
}
    