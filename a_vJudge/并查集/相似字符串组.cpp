#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,fa[N],sets;

vector<string> strs(N);

void build(int n){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    sets=n;
}

int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}
void uni(int x,int y){
    int fx = find(x);
    int fy = find(y);
    fa[fy] = fx;
    sets--;
}

signed main() {
    cin>>n;

    build(n);
    for(int i=1;i<=n;i++){
        cin>>strs[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(find(i)!=find(j)){
                if(strs[i].size()!=strs[j].size()) continue;
                int diff = 0;
                for(int k=0;k<strs[i].size() && diff<=2;i++)
                    if(strs[i][k]!=strs[j][k]) diff++;
                if(diff==0 || diff==2)
                    uni(i,j);
            }
        }
    }

    printf("共有%lld种相似字符串组",sets);
    return 0;
}
    