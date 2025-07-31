#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 100010;
int t[N],v[N],f[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&t[i],&v[i]);
		
	for(int i=1;i<=n;i++)
		for(int j=m;j>=t[i];j--)
			f[j]=max(f[j],f[j-t[i]]+v[i]);
			
	printf("%d",f[m]);
	return 0;
}