#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 12, inf = 1e9, mod = 1e9+7;
int n,m,sx,sy,vis[N][N];
int a[N][N];
struct Node{
    int x,y,t,hp;
};
int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};
queue<Node> q;

int bfs(){
    q.push({sx,sy,0,6});
    vis[sx][sy]=6;
        Node cur = q.front();q.pop();
        int x = cur.x;
        int y = cur.y;
        int t = cur.t;
        int hp = cur.hp;

        if(a[x][y]==3) return cur.t;
        else if(a[x][y]==4) hp=6;
        
        for(int i=0;i<4;i++){
            int xx = x+dirx[i];
            int yy = y+diry[i];
            if(xx<1||xx>n||yy<1||yy>m) continue;
            // 剪枝也是门技巧，你开三维数组堆太多，直接爆内存
            if(hp-1<=vis[xx][yy]) continue;
            else vis[xx][yy] = hp;
            if(a[xx][yy]){
                vis[xx][yy] = hp-1;
                if(hp > 1)
                    q.push({xx,yy,t+1,hp-1});
            }
        }
            
        return -1;
    }


// 0：障碍物。
// 1：空地， 小 H 可以自由行走。
// 2：小 H 出发点， 也是一片空地。
// 3：小 H 的家。
// 4：有鼠标在上面的空地。

signed main() {
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]==2) sx=i,sy=j;
        }
    }

    cout<<bfs();
    return 0;
}
    