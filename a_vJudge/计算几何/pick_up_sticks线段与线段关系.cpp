#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;
struct Point{double x,y;};
Point operator-(Point a,Point b){return Point{a.x-b.x,a.y-b.y};}
double cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
double cross(Point a,Point b,Point c){return cross(b-a,c-a);}

signed main() {
    cin>>n;
    vector<Point> pa(n+1),pb(n+1);
    vector<bool> ans(n+1,true);
    for(int i=1;i<=n;i++){
        cin>>pa[i].x>>pa[i].y>>pb[i].x>>pb[i].y;
        for(int j=1;j<i;j++){
            // 线段与线段相交
            if(
                cross(pa[i],pb[i],pa[j])*cross(pa[i],pb[i],pb[j]) <= 0
                ||
                cross(pa[j],pb[j],pa[i])*cross(pa[j],pb[j],pb[i]) <= 0
            ) ans[j]=false;
        }
    
    }

    for(int i=1;i<=n;i++) if(ans[i]) cout<<i<<" ";
    return 0;
}
    