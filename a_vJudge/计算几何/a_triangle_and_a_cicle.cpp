#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
const double eps = 1e-6, PI = acos(-1);
// 基本运算符
struct Point{double x,y;};
double dis(Point a,Point b){return hypot(a.x-b.x,a.y-b.y);}
double len(Point a){return dis(a,{0,0});}
Point operator+(Point a,Point b){return Point{a.x+b.x,a.y+b.y};}
Point operator-(Point a,Point b){return Point{a.x-b.x,a.y-b.y};}
Point operator*(Point a,double b){return Point{a.x*b,a.y*b};}
Point operator/(Point a,double b){return Point{a.x/b,a.y/b};}
double operator&(Point a,Point b){return a.x*b.x+a.y*b.y;}
double operator*(Point a,Point b){return a.x*b.y-a.y*b.x;}
double cross(Point a,Point b,Point c){return (b-a)*(c-a);}
Point norm(Point a){return Point(a/len(a));}
Point rotate(Point a,double b){return Point{a.x*cos(b)-a.y*sin(b), a.x*sin(b)+a.y*cos(b)};}
bool onSegment(Point p,Point a,Point b){return (p-a)*(p-b)<eps && ((p-a)&(p-b)) < 0;}

// 全局变量
int n,m;
Point a,b,o;
double R;

// 运算函数

// 计算交点
Point getNode(Point a,Point u,Point b,Point v){
    double t = (a-b)*v/(v*u);
    Point p = a + u*t;
    return p;
}

// 计算线段AB到圆的距离，垂足偏向BA方向的交点pa，垂足偏向AB方向的交点pb
double getDP2(Point a, Point b, Point &pa, Point &pb){
    Point e = getNode(a,b-a,o,rotate(b-a,PI/2));
    double d = dis(o,e);
    // 圆心到直线的垂足不在线段上
    if(!onSegment(e,a,b)) d = min(dis(o,e),dis(o,a));
    // 圆心到线段的距离大于半径
    if(d>=R) return d;

    // 圆心到线段的距离小于半径
    double len = sqrt(R*R-dis(o,e)*dis(o,e));
    pa = e + norm(b-a) * len;
    pb = e + norm(a-b) * len;
    return d;
}

// 计算OA和OB与圆围成的扇形面积
double sector(Point a,Point b){
    double angle = acos((a&b)/len(a)/len(b));
    if(a*b<0) angle = -angle;
    return R*R*angle/2;
}

// 计算三角形和圆公共部分面积
double getArea(Point a,Point b){
    // 圆心在直线上
    if(abs(a*b) < eps) return 0;
    double da = dis(a,o);
    double db = dis(b,o);
    if(da<=R && db<=R) return a*b/2;

    Point pa,pb;
    double d = getDP2(a,b,pa,pb);
    if(d >= R) return sector(a,b);
}

signed main() {
    cin>>a.x>>a.y>>b.x>>b.y>>o.x>>o.y;
    cin>>R;
    cout<<getArea(a,b);
    return 0;
}
    