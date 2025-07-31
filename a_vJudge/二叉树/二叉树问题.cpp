#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m;

vector<int> treenode[N];
int maxD[N],depth[N];
bool vis[N];

struct Node{
    int idx = 0;
    int d = 0;
};

void build(){
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        treenode[u].push_back(v);
        treenode[v].push_back(u);
    }
}

int maxDepth(int head){
    if(!head) return 0;
    vis[head] = true;

    int res = 0;
    for(int i=0;i<treenode[head].size();i++){
        if(vis[treenode[head][i]]) continue;
        res = max(res,maxDepth(treenode[head][i]));
    }
    return res+1;
}

int maxWidth(int head){
    int res = 0;

    queue<Node> q;
    q.push({1,1});
    while(q.size()){
        Node front = q.front();q.pop();
        
        int cur = front.idx;
        int d = front.d;
        if(vis[cur]) continue;
        vis[cur] = true;
        depth[cur] = d;
        maxD[d]++;
        res = max(maxD[d],res);


        for(int i=0;i<treenode[cur].size();i++){
            q.push({treenode[cur][i],d+1});
        }
    }

    return res;
}

int LCA(int head, int x,int y){
    // xy包含关系
    if(head == x || head == y) return head;

    // xy分叉关系
    int left[2]={0,0};
    int j = 0;
    for(int i=0;i<treenode[head].size();i++){
        int cur = treenode[head][i];
        if(vis[cur]) continue;
        vis[cur] = true;
        // 不吃回头草
        left[j++] = LCA(cur,x,y);
    }
    
    // cout << head << " "<< left[0] << " " << left[1] << endl;
    if(left[0] && left[1]) return head;
    if(!left[0] && !left[1]) return 0;

    return left[0] ? left[0] : left[1];
}

int Distance(int x,int y){
    
    int mid = LCA(1,x,y);
    return (depth[x]-depth[mid])*2 + depth[y]-depth[mid];
}

signed main() {
    cin>>n;
    build();
    // 计算二叉树的深度
    memset(vis,0,sizeof vis);
    cout << maxDepth(1) << "\n";

    // 计算二叉树的宽度
    memset(vis,0,sizeof vis);
    cout << maxWidth(1) << "\n";

    // 计算x和y的距离
    int x,y;
    cin>>x>>y;
    memset(vis,0,sizeof vis);
    vis[1]=true;
    
    cout << Distance(x,y);
    
    return 0;
}
    