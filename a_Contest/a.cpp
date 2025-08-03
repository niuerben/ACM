#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,a,b;

signed main() {
	cin>>n>>a>>b;
	string s;
	cin>>s;
	for(int i=a;i+b<s.size();i++) cout<<s[i];
	return 0;
}
	