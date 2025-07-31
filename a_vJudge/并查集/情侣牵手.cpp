#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m,a[N],father[N],Size[N],Stack[N],sets;

// 初始化并查集
void build(){
    for(int i=0;i<n/2;i++){
        father[i]=i;
    }
}

// 查找i所在集合的代表元素
int find(int i){
    if(father[i]!=i) return father[i] = find(father[i]);
    return father[i];
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
        father[fy] = fx;
        sets--;
    }
}


signed main() {
    // 混在一起的k对情侣至少交换k-1次
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sets = n/2;
    build(); 
    
    for(int i=0;i<n;i+=2){
        unionSet(a[i]/2,a[i+1]/2);
    }

    for(int i=0;i<n;i++) cout<<father[a[i]/2]<<" ";
    
    // cout<<n/2-sets;
    return 0;
}
    