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
double cross(Point a,Point b,Point c){return cross(b-a,c-a);}
struct Line{Point a,b;};


signed main() {
    cin>>n;
    vector<Point> p(2*n+1);
    vector<Line> l(n+1);
    for(int i=1;i<=2*n;i+=2) {
        cin>>p[i].x>>p[i].y>>p[i+1].x>>p[i+1].y;
        l[i+1>>1] = {p[i],p[i+1]};
    }

    for(int i=1;i<=2*n;i++){
        for(int j=i+1;j<=2*n;j++){
            bool flag = true;
            
            if(p[i].x==p[j].x && p[i].y==p[j].y) continue;
            for(int k=1;k<=n && flag;k++){
                cout<<k<<" ";

                // 直线与线段相交
                if(cross(p[i],p[j],l[k].a)*cross(p[i],p[j],l[k].b)>0) {
                    flag = false;
                }
            }
            if(flag) {
                cout<<"YES"<<'\n';
                return 0;
            }
        }
    }
    return 0;
}
    