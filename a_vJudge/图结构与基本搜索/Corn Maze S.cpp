#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 310, inf = 1e9, mod = 1e9+7;
int n,m,sx,sy,vis[N][N];
char a[N][N];
map<char,pair<int,int> > mp;
map<pair<int,int>,pair<int,int> > ne;
struct Node{
    int x,y,t;
};
int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};
queue<Node> q;

int bfs(){
    q.push({sx,sy,0});
    while(q.size()){
        Node cur = q.front();q.pop();
        int x = cur.x;
        int y = cur.y;
        int t = cur.t;
        if(a[x][y]=='='){
            return cur.t;
        }

        for(int i=0;i<4;i++){
            int xx = x+dirx[i];
            int yy = y+diry[i];
            if(xx<1||xx>n||yy<1||yy>m||vis[xx][yy]) continue;
            if(a[xx][yy]=='.' || a[xx][yy]=='='){
                vis[xx][yy] = true;
                q.push({xx,yy,t+1});
            }
            else if(isalpha(a[xx][yy])){
                vis[xx][yy] = true;
                // 使用结构化绑定获取pair对象
                auto[tox,toy] = ne[{xx,yy}];
                q.push({tox,toy,t+1});
            }
        }
            
    }
}


signed main() {
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(isalpha(a[i][j])) {
                // 键的存在性检查
                if(!mp.count(a[i][j]))
                    mp[a[i][j]]={i,j};
                else{
                    auto [li,lj]=mp[a[i][j]];
                    ne[{i,j}]={li,lj};
                    ne[{li,lj}]={i,j};
                }

            }
            else if(a[i][j]=='@') sx=i,sy=j;
        }
    }

    cout<<bfs();
    return 0;
}
    