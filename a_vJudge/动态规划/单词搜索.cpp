#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9, mod = 1e9+7;
int n,m;
char a[N][N];
int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};
int vis[N][N];

bool f(int i,int j,string word,int len){
    int ans = false;
    if(a[i][j] != word[len]) return false;
    if(len+1 == word.size()) return true;
    vis[i][j]=true;
 
    for(int k=0;k<4;k++){
        int x = i+dirx[k], y = j+diry[k];
        if(x<0 || x>n || y<0 || y>m || vis[x][y]) continue;
        ans |= f(x,y,word,len+1);
    }
    
    vis[i][j] = false;
    return ans;
}

signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    string word;
    cin >> word;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(f(i,j,word,0)) {
                cout <<"Yes"<<'\n';
                return 0;
            }
        }
    }
    
    cout<<"No"<<'\n';
    return 0;
}

/*
决定返回值的不止有i,j,k，不能用状态转移方程表示
*/