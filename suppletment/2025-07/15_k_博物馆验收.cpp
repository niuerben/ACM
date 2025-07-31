#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10, inf = 1e9, mod = 1e6+7;
int n,m, a[N],d[N][4], u[N], dp[N][4],dp2[N][4],vis[N][4];

int cnt;
// t从哪个门进
int dfs(int i,int t){
	if(dp[i][t] == true) return cnt;
	if(dp2[i][t]) return dp2[i][t];

	// 到v去
	int v = d[i][t%u[i]+1];

	// 在v处第tt扇门可以回来
	int tt;
	for(int j=1;j<=u[v];j++) if(d[v][j]==i){
		tt = j;
		break;
	} 
	// cout << i<<" "<<v<<endl;

	if(!vis[i][t%u[i]+1] && !vis[v][tt]) cnt++;
	dp[i][t] = true;
	vis[i][t%u[i]+1] = true;
	vis[v][tt] = true;

	dp2[i][t] = dfs(v,tt);

	dp[i][t] = false;
	vis[i][t%u[i]+1] = false;
	vis[v][tt] = false;
	return dp2[i][t];
}

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>u[i];
		for(int j=1;j<=u[i];j++) {
			cin>>d[i][j];
		}
	}

	for(int i=1;i<=n;i++){
		cnt=0;

		cout<< dfs(i,0) << endl;
	}
    return 0;
}

// 相同的环都是一个环，找到一次就记忆化，不同环加起来跑的节点也不会超过3*n