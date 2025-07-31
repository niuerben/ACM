#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,stones[N][2],fa[N],sets;

map<int,int> colum,row;
void build(){
    for(int i=0;i<=n;i++){
        fa[i]=i;
        sets++;
    }
}

int find(int x){
    if(x!=fa[x]) return fa[x]=find(fa[x]);
    return fa[x];
}

void uni(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx!=fy){
        fa[fx]=fy;
        sets--;
    }
}

signed main() {
    cin>>n;
    build();
    for(int i=1;i<=n;i++){
        cin>>stones[i][0]>>stones[i][1];
        int x = stones[i][0];
        int y = stones[i][1];
        if(colum[x]==0){
            colum[x]=i;
        }
        else{
            uni(i,colum[x]);
        }
        if(row[y]==0){
            row[y]=i;
        }
        else{
            uni(i,row[y]);
        }
    }
    cout<<n-sets;
    return 0;
}
