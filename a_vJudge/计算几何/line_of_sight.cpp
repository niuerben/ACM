#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;
struct Point{double x,y;};
double dis(Point a,Point b){return hypot(a.x-b.x,a.y-b.y);}
Point operator+(Point a,Point b){return Point{a.x+b.x,a.y+b.y};}
Point operator-(Point a,Point b){return Point{a.x-b.x,a.y-b.y};}
Point operator*(Point a,double b){return Point{a.x*b,a.y*b};}
double operator*(Point a,Point b){return a.x*b.y-a.y*b.x;}
double dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
double cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
double cross(Point a,Point b,Point c){return cross(b-a,c-a);}
struct Line{Point a,b;};
Line house;
Line spect;
// 直线交点
Point getNode(Point a,Point u,Point b,Point v){
    double t = (a-b)*v/(v*u);
    Point p = a + u*t;
    if(p.x>house.b.x) p.x=house.b.x;
    if(p.x<house.a.x) p.x=house.a.x;
    return p;
}

signed main() {
    
    vector<Line> obstacle(n+1);
    cin>>house.a.x>>house.a.y>>house.b.x>>house.b.y;
    cin>>spect.a.x>>spect.a.y>>spect.b.x>>spect.b.y;
    vector<Point> shadow;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>obstacle[i].a.x>>obstacle[i].a.y>>obstacle[i].b.x>>obstacle[i].b.y;

        double l1 = getNode(spect.a, obstacle[i].a - spect.a, house.a, house.b-house.a).x;
        double r1 = getNode(spect.b, obstacle[i].a - spect.b, house.a, house.b-house.a).x;
        shadow.push_back({min(l1,r1),max(l1,r1)});

        double l2 = getNode(spect.a, obstacle[i].b - spect.a, house.a, house.b-house.a).x;
        double r2 = getNode(spect.b, obstacle[i].b - spect.b, house.a, house.b-house.a).x;        
        shadow.push_back({min(l2,r2),max(l2,r2)});
    }

    // 排序阴影
    sort(shadow.begin(),shadow.end(),[](Point a,Point b){
        return a.x == b.x ? a.y<b.y : a.x<b.x;
    });

    double last = house.a.x;
    double cur;
    double ans = 0;
    for(int i=0;i<shadow.size();i++){
        cur = shadow[i].x;
        if(cur>last) ans = max(ans,cur-last);
        last = shadow[i].y; 
    }

    cout<<ans;
    return 0;
}
    