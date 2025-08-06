#include<bits/stdc++.h>
using namespace std;
const int N = 5001, M = N*(N-1)/2;
int n,m,x[N],y[N],done[N];

struct Node{
    int u,v;
    double w;
};


double kruskal(){
    int cnt = 0;
    double res = 0;
    for(int u=1;u<=n;u++){
		if(done[u]) continue;
		done[u] = true;
        if(cnt==n-1) break;
		for(int v=1;v<=n;v++){
			if(done[v]) continue;
			done[v] = true;
			// cout << u<<" "<<v<<endl;
			res += hypot(x[u]-x[v],y[u]-y[v]);
			cnt++;
		}
    }
    return res;
}

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }

    printf("%.2lf",kruskal());
    return 0;
}
    