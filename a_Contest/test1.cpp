#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int indegree[N],vis[N],ans[N],n;
std::vector<int> dir[N];

void bfs(){
    std::priority_queue<int,std::vector<int>,std::greater<int>> q;
    for(int i=1;i<=n;i++)
        if(!indegree[i]) q.push(i);
    int cnt = 0,u;
    while(!q.empty()){
        u=q.top();
        q.pop();
        ans[cnt++]=u;
        for(int i=dir[u].size()-1;i>=0;i--){
            if(vis[dir[u][i]]) continue;
            if(--indegree[dir[u][i]]==0) q.push(dir[u][i]);
        }        
    }
    for(int i=0;i<cnt-1;i++) printf("%d ",ans[i]);
    printf("%d",ans[cnt-1]);
}

int main(){

    int m,a,b;
    while(~scanf("%d%d",&n,&m)){
        memset(indegree+1,0,sizeof(int)*n);
        memset(vis+1,0,sizeof(int)*n);
        for(int i=1;i<=n;i++) dir[i].clear();
        while(m--){
            scanf("%d%d",&a,&b);
            dir[a].push_back(b);
            indegree[b]++;
        }
        bfs();
    }
    return 0;
}