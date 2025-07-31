#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;
struct Point{double x,y;};
Point operator-(Point a,Point b){return Point{a.x-b.x,a.y-b.y};}
double cross(Point a,Point b){return a.x*b.y-a.y*b.x;}

signed main() {
    int n,m,x1,y1,x2,y2;
    while(cin>>n>>m>>x1>>y1>>x2>>y2){
        if(n==0) break;
        // 输入上下边上点的横坐标
        vector<Point> a(n+2),b(n+2),p(m+1);
        vector<int> c(n+1);
        a[0].x = x1; a[0].y = y1;
        b[0].x = x1; b[0].y = y2;
        for(int i=1;i<=n;i++) {cin>>a[i].x>>b[i].x;a[i].y=y1;b[i].y=y2;}
        a[n+1].x = x2; a[n+1].y = y1;
        b[n+1].x = x2; b[n+1].y = y2;
    
        for(int i=1;i<=m;i++){
            cin>>p[i].x>>p[i].y;
        }

        for(int i=1;i<=m;i++){
            int l=0,r=n+1;
            while(l<r){
                int mid = l+r>>1;
                if(cross(p[i]-b[mid],a[mid]-b[mid])<0) r = mid;
                else l = mid+1;
            }
            c[l-1]++;
        }

        for(int i=0;i<=n;i++) cout<<i<<": "<<c[i]<<"\n";
        cout<<endl;
    }
    return 0;
}
    