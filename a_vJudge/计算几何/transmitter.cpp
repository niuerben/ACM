#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;

struct Point{double x,y;};
double dis(Point a,Point b){return hypot(a.x-b.x,a.y-b.y);}
Point operator-(Point a,Point b){return Point{a.x-b.x,a.y-b.y};}
double dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
double cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
signed main() {
    double x0,y0,r;
    while(cin>>x0>>y0>>r){
        if(r<=0) break;
        Point p0 = {x0,y0};
        // 读入点
        cin>>n;
        vector<Point> vec;
        for(int i=1;i<=n;i++){
            double x,y;
            cin>>x>>y;
            // 筛查距离小的点
            if(dis(Point{x,y},Point{x0,y0})<=r) vec.push_back({x,y});
        }
    
        int ans = 0;
        // 枚举始边
        for(int i=0;i<vec.size();i++){
            int res = 1;
            // 枚举终边
            for(int j=0;j<vec.size();j++){
                if(i==j) continue;
                if(cross(vec[i]-p0,vec[j]-p0)>=0) res++;
            }
            ans = max(ans,res);
        }
    
        cout<<ans<<endl;

    }
    return 0;
}
    