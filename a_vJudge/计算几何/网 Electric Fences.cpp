#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10, inf = 1e9, mod = 1e9+7;
const double eps = 1e-6;
double n,m,p;
int l[N],r[N],ans;

signed main() {
	cin>>n>>m>>p;
	for(int i=1;i<m;i++){
		l[i] = ceil(n*i/m+eps);
	}

	for(int i=1;i<m;i++){
		r[i] = floor((n-p)*i/m+p-eps);
		// cout<<(n-p)*i/m+p<<'\n';
	}

	for(int i=1;i<m;i++){
		// cout<<l[i]<<" "<<r[i]<<endl;
		ans += r[i]-l[i]+1;
	}

	cout<<ans;
}
	