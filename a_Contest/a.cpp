#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
const double eps = 1e-6, PI = acos(-1);
// 基本运算符
struct Point{double x,y;};
double dis(Point a,Point b){return hypot(a.x-b.x,a.y-b.y);}
int len2(Point a,Point b){return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
Point operator+(Point a,Point b){return Point{a.x+b.x,a.y+b.y};}
Point operator-(Point a,Point b){return Point{a.x-b.x,a.y-b.y};}
Point operator*(Point a,double b){return Point{a.x*b,a.y*b};}
Point operator/(Point a,double b){return Point{a.x/b,a.y/b};}
double operator&(Point a,Point b){return a.x*b.x+a.y*b.y;}
double operator*(Point a,Point b){return a.x*b.y-a.y*b.x;}
double cross(Point a,Point b,Point c){return (b-a)*(c-a);}
Point rotate(Point a,double b){return Point{a.x*cos(b)-a.y*sin(b), a.x*sin(b)+a.y*cos(b)};}
bool onSegment(Point p,Point a,Point b){return (p-a)*(p-b)<eps && ((p-a)&(p-b)) < 0;}

// 全局变量
int n,m;
vector<Point> p;
vector<Point> s;

// 运算函数
// 求凸包栈
void Andrew(){
    sort(p.begin(),p.end(),[](Point a,Point b){
        return a.x==b.x ? a.y<b.y : a.x<b.x;
    });

    int top = 0;
    // 下凸包
    for(int i=1;i<=n;i++){
        // 把栈内不合题意的线段删除干净
        while(top>1 && cross(s[top-1],s[top],p[i]) < 0) top--;
        s[++top] = p[i];
    }

    int t = top;
    for(int i=n-1;i>=1;i--){
        // 把栈内不合题意的线段删除干净
        while(top>t && cross(s[top-1],s[top],p[i]) < 0) top--;
        s[++top] = p[i];
    }

    n = top-1;
}

// 旋转卡壳计算最远点
int rotating_calipers(){
    int res = 0;
    for(int i=1, j=2; i<=n;i++){
        while(cross(s[i],s[i+1],s[j]) < cross(s[i],s[i+1],s[j%(n+1)+1])) j = j%(n+1)+1;
        res = max(res,max(len2(s[i],s[j]),len2(s[i+1],s[j])));
    }
    return res;
}

signed main() {
    cin>>n;
    p.reserve(n+1);
    s.reserve(4*n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }   
    
    
    // Andrew算法
    Andrew();
    cout << rotating_calipers();
    return 0;
}
    