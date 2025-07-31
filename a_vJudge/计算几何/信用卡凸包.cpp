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
double a,b,r;
vector<Point> p;

// 运算函数

double Andrew(){
    sort(p.begin(),p.end(),[](Point a,Point b){
        return a.x==b.x ? a.y<b.y : a.x<b.x;
    });

    vector<Point> s(16*n+1);
    int top = 0;
    // 下凸包
    for(int i=0;i<4*n;i++){
        // 把栈内不合题意的线段删除干净
        while(top>1 && cross(s[top-1],s[top],p[i]) <= 0) top--;
        s[++top] = p[i];
    }

    int t = top;
    for(int i=4*n-2;i>=0;i--){
        // 把栈内不合题意的线段删除干净
        while(top>t && cross(s[top-1],s[top],p[i]) <= 0) top--;
        s[++top] = p[i];
    }

    double res = 0;
    for(int i=1;i<top;i++) res+=dis(s[i],s[i+1]);
    return res;
}



signed main() {
    cin>>n;
    cin>>b>>a>>r;
    
    Point center_to_vertex1 = {a/2-r,b/2-r};
    Point center_to_vertex2 = {-(a/2-r),b/2-r};
    Point center_to_vertex3 = {a/2-r,-(b/2-r)};
    Point center_to_vertex4 = {-(a/2-r),-(b/2-r)};

    for(int i=1;i<=n;i++){
        double x,y,xita;
        cin>>x>>y>>xita;
        p.push_back(Point{x,y}+rotate(center_to_vertex1,xita));
        p.push_back(Point{x,y}+rotate(center_to_vertex2,xita));
        p.push_back(Point{x,y}+rotate(center_to_vertex3,xita));
        p.push_back(Point{x,y}+rotate(center_to_vertex4,xita));
    }   
    
    // Andrew算法
    double ans = Andrew()+2*PI*r;
    printf("%.2lf",ans);
    return 0;
}
    