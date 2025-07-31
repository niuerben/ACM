#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,father[N],Size[N],Stack[N];

// 初始化并查集
void build(){
    for(int i=0;i<=n;i++){
        father[i]=i;
        Size[i]=1;
    }
}

// 查找i所在集合的代表元素
int find(int i){
    int cnt = 0;
    while(i!=father[i]){
        Stack[++cnt] = i;
        i = father[i];
    }

    // 扁平化
    for(int j=1;j<=cnt;j++){
        father[Stack[i]] = i;
        // Size[Stack[i]] = Size[i];
    }

    return i;
}

// 判断x,y在不在一个集合
bool isSameSet(int x,int y){
    int fx = find(x);
    int fy = find(y);
    return fx == fy;
}

// x所在集合与y所在集合所有元素合并成一个集合
void unionSet(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx!=fy){
        // 小挂大
        if(Size[fx]>=Size[fy]){
            father[fy] = fx;
            Size[fx] += Size[fy];
        }
        else{
            father[fx] = fy;
            Size[fy] += Size[fx];
        }
    }
}

signed main() {
    cin>>n>>m;
    build();

    while(m--){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            continue;
        }
        else if(op==2){
            unionSet(x,y);
        }
        else if(op==3) {
            if(isSameSet(x,y)) cout<<"Yes"<<'\n';
            else cout <<"No"<<'\n';
        }
    }
    return 0;
}
    