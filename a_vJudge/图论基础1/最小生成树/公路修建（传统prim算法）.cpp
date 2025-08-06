#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
int n,m,x[N],y[N],done[N];
double dis[N];

// 无堆优化的传统prim算法（处理稠密图）
double prim(){

    double ans = 0;
    for(int i=1;i<=n;i++) dis[i] = 1e9;
    dis[1] = 0.0;
    for(int u=1;u<=n;u++){
        // 寻找最近点
        int minV = 1;
        double minW = 1e9;
        for(int v=1;v<=n;v++){
            if(done[v]) continue;
            if(dis[v] < minW){
                minV = v;
                minW = dis[v];
            }
        }

        // 标记该点
        done[minV] = true;
        ans += minW;

        // 更新边权
        for(int j=1;j<=n;j++){
            dis[j] = min(dis[j],hypot(x[minV]-x[j],y[minV]-y[j]));
        }
    }
    return ans;
}

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }

    printf("%.2lf",prim());
    return 0;
}
    