#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e6+7;
int n,m,addr[N];
// 依旧是分组背包
struct Node{
    int v;
    int p;
};
vector<vector<Node> > vec(70);
vector<vector<Node>> vec2;
int dp[N];

signed main() {
    cin>>m>>n;
 
    int vv,pp,qq;
    for(int i=1;i<=n;i++){
        cin>>vv>>pp>>qq;
        if(qq==0) {
            if(vec[i].size()) vec[i][0] = {vv,vv*pp};
            else vec[i].push_back({vv,vv*pp});
        }
        else {
            if(vec[qq].empty()) vec[qq].push_back({0,0});
            vec[qq].push_back({vv,vv*pp});
        }
        
    }


    for(int i=0;i<vec.size();i++){
        if(vec[i].size()==0) continue;
        if(vec[i].size() == 1){
            vector<Node> tmp{{vec[i][0].v,vec[i][0].p}};
            vec2.push_back(tmp);
        }
        else if(vec[i].size() == 2){
            vector<Node> tmp;
            tmp.push_back({vec[i][0].v,vec[i][0].p});
            tmp.push_back({vec[i][0].v+vec[i][1].v,vec[i][0].p+vec[i][1].p});
            vec2.push_back(tmp);
        }
        else if(vec[i].size() == 3){
            vector<Node> tmp;
            tmp.push_back({vec[i][0].v,vec[i][0].p});
            tmp.push_back({vec[i][0].v+vec[i][1].v,vec[i][0].p+vec[i][1].p});
            tmp.push_back({vec[i][0].v+vec[i][2].v,vec[i][0].p+vec[i][2].p});
            tmp.push_back({vec[i][0].v+vec[i][1].v+vec[i][2].v,vec[i][0].p+vec[i][1].p+vec[i][2].p});
            vec2.push_back(tmp);
        }
    }


    for(int i=0;i<vec2.size();i++)
		for(int j=m;j>=0;j--)
			for(int k=0;k<vec2[i].size();k++)
				if(j>=vec2[i][k].v) dp[j]=max(dp[j],dp[j-vec2[i][k].v]+vec2[i][k].p);
	

	cout<<dp[m];

    return 0;
}
