#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,idx;

struct TreeNode{
    int idx = -1;
    int x = 0;
    int left = -1;
    int right = -1;
    
    bool operator<(const TreeNode& other)const{
        return x != other.x ? x > other.x : idx > other.idx;
    }
};

TreeNode treenode[N];
map<int,string> mp;

void dfs(int cur,string path){

    if(cur == -1) return;
    int x = treenode[cur].x;
    int idx = treenode[cur].idx;
    int left = treenode[cur].left;
    int right = treenode[cur].right;
    
    if(left == -1 && right == -1){
        mp[idx] = path;
    }

    // if(cur==4)cout<<cur<<" "<<left<<" "<<right<<endl;
    dfs(left,path+"0");
    dfs(right,path+"1");
}


signed main() {
    for(int n=2;n<=4;n++){
        priority_queue<TreeNode> q;
        
        for(int i=1;i<=n;i++) {
            int x = abs(100*sin(i*1000));
            idx++;
            treenode[idx] = {idx,x,-1,-1};
            q.push(treenode[idx]);
        }
        
        // 构建哈夫曼树
        while(q.size() > 1){
            TreeNode a = q.top();q.pop();
            TreeNode b = q.top();q.pop();
    
            idx++;
            // cout << idx <<" "<<a.idx<<" "<<b.idx<<endl;
            treenode[idx] = {idx,a.x+b.x,a.idx,b.idx};
            q.push(treenode[idx]);
        }
    
        // 编码哈夫曼树
        dfs(idx,"");
        for(auto [key,val]:mp){
            cout<<key<<endl;
            cout << treenode[key].x << "-" << val << "\n";
        }
    
        // 删除哈夫曼树
        for(int i=0;i<=idx;i++){
            treenode[idx] = {-1,0,-1,-1};
        }
        idx = 0;
        mp.clear();
        cout<<endl;
    }
    
    return 0;
}
    