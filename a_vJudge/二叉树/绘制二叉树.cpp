#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m;
int edge[N],achor[N],remainH[N];
char graph[2010][2010];

void full(int x,int y,int level){
    if(level > n) return;

    graph[x][y] = 'o';
    // 画斜线
    for(int i=1;i<=edge[level];i++){
        graph[x+i][y-i] = '/';
        graph[x+i][y+i] = '\\';
    }

    full(x+edge[level]+1,y-edge[level]-1,level+1);
    full(x+edge[level]+1,y+edge[level]+1,level+1);

}

void Delete(int x,int y,int level){
    
    if(level > n) return;

    graph[x][y] = ' ';
    for(int i=1;i<=edge[level];i++){
        graph[x+i][y-i] = ' ';
        graph[x+i][y+i] = ' ';
    }

    Delete(x+edge[level]+1,y-edge[level]-1,level+1);
    Delete(x+edge[level]+1,y+edge[level]+1,level+1);
    
}

signed main() {
    cin>>n>>m;
    // 第n层的边长
    edge[n] = 0;
    edge[n-1] = 1;
    remainH[n] = 1;
    remainH[n-1] = 3;
    for(int i=n-2;i>=1;i--){
        edge[i] = 3*(1<<(n-i-2)) - 1;
        remainH[i] = remainH[i+1] + edge[i] + 1;
    }
    

    for(int i=1;i<=n;i++){
        achor[i] = achor[i-1] + edge[i-1] + 1;
    }


    // 顶点坐标
    int midy = 3*(1<<(n-2));
    int midx = 1;

    memset(graph,' ',sizeof graph);
    full(midx,midy,1);
    
    while(m--){
        int x,y;
        cin>>x>>y;
        int level = x;

        x = achor[x];
        int h = edge[level];
        int Len;
        if(level!=n) {
            Len = remainH[level];
            y = (2*Len)*(y-1) + remainH[level];
        }
        // 太过细节的分类
        else {
            if(y&1) y = 3*(y-1)+1;
            else y = 3*y-1;
        }

        // 清除上方残边
        int up = 1;
        while(graph[x-up][y+up]=='/'){
            graph[x-up][y+up] = ' ';
            up++;
        }
        up = 1;
        while(graph[x-up][y-up]=='\\'){
            graph[x-up][y-up] = ' ';
            up++;
        }
        Delete(x,y,level);
    }
    for(int i=1;i<=midy;i++){
        for(int j=1;j<2*midy;j++){
            cout<<graph[i][j];
        }
        cout<<'\n';
    }
    

    return 0;
}
    