#include<bits/stdc++.h>
using namespace std;

// 判断浮点数相等及符号
const double pi = acos(-1.0);
const double eps = 1e-8;
int sgn(double x){
    if(abs(x)<eps) return 0;
    else return x>0? 1:-1;
}

int dcmp(double x,double y){
    if(abs(x-y)<eps) return 0;
    else return x<y? -1:1;
}



// 点
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (Point B){return Point(x+B.x,y+B.y);}
    Point operator - (Point B){return Point(x-B.x,y-B.y);}
    Point operator * (double k){return Point(x*k,y*k);}
    Point operator / (double k){return Point(x/k,y/k);}
    bool operator == (Point B){return sgn(x-B.x)==0 && sgn(y-B.y)==0;}
};

// 两点距离
double Distance(Point A,Point B){return hypot(A.x-B.x,A.y-B.y);};



// 向量
typedef Point Vector;
double Dot (Vector A,Vector B){return A.x*B.x+A.y*B.y;} // 点积
double Len(Vector A){return sqrt(Dot(A,A));}
double Len2(Vector A){return Dot(A,A);} // 长度的平方
double Angle(Vector A,Vector B){return acos(Dot(A,B)/Len(A)/Len(B));}
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;} // 叉积
double Area2(Point A,Point B,Point C){return Cross(A-B,A-C);}
Vector Rotate(Vector A,double rad){ // 逆时针旋转rad
    return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
Vector Normal(Vector A){return Vector(-A.y/Len(A),A.x/Len(A));}
// Vector Normal(Vector A){return Rotate(A,pi/2)/Len(A);
bool Parallel(Vector A,Vector B){return sgn(Cross(A,B)) == 0;}


// 直线
struct Line{
    Point p1,p2;
    Line(){}
    Line(Point p1, Point p2):p1(p1),p2(p2){}
    Line(Point p, double angle){
        p1 = p;
        if(sgn(angle - pi/2) == 0) {p2 = p1 + Point(0,1);}
        else{p2 = (p1 + Point(1,tan(angle)));}
    }
    Line(double a,double b,double c){   // ax + by + c = 0
        if(sgn(a) == 0){
            p1 = Point(0,-c/b);
            p2 = Point(1,-c/b);
        }
        else if(sgn(b) == 0){
            p1 = Point(-c/a,0);
            p2 = Point(-c/a,1);
        }
        else{
            p1 = Point(0,-c/b);
            p2 = Point(1,(-a-c)/b);
        }
    }
};

typedef Line Segment;

int Point_line_relation(Point p, Line v){
    int c = sgn(Cross(p-v.p1, v.p2-v.p1));
    if(c > 0) return 1; // 1: p在v的左侧
    if(c < 0) return 2; // 2: p在v的右侧
    return 0;           // 3: p在v上
}

bool Point_on_seg(Point p, Line v){
    if(sgn(Cross(p-v.p1,v.p2-v.p1) == 0) && sgn(Dot(p-v.p1,p-v.p2) <= 0)) return true;
    return false;
}

double Dis_point_line(Point p,Line v){
    return abs(Cross(p-v.p1,v.p2-v.p1)/Distance(v.p2,v.p1));
}

Point Point_line_proj(Point p, Line v){
    double k = Dot(p-v.p1,v.p2-v.p1)/Len2(v.p2-v.p1);
    return v.p1+(v.p2-v.p1)*k;
}

Point Point_line_symmetry(Point p, Line v){
    Point q = Point_line_proj(p,v);
    return Point(2*q.x-p.x,2*q.y-p.y);
}

double Dis_point_seg(Point p,Segment v){
    if(sgn(Dot(p-v.p1,v.p2-v.p1)) < 0 || sgn(Dot(p-v.p2,v.p1-v.p2)) < 0)
        return min(Distance(p,v.p1),Distance(p,v.p2));
    return Dis_point_line(p,v);
}

int Line_relation(Line v1, Line v2){
    if(sgn(Cross(v1.p2-v1.p1,v2.p2-v2.p1)) == 0){
        if(Point_line_relation(v1.p1,v2) == 0) return 1;   // 1: 重合
        else return 0;                                          // 0: 平行
    }
    return 2;                                                   // 2: 相交
}

Point Cross_point(Point a,Point b,Point c,Point d){
    double s1 = Cross(b-a,c-a);
    double s2 = Cross(b-a,d-a);
    return Point(c.x*s2-d.x*s1,c.y*s2-d.y*s1)/(s2-s1);
}

bool Cross_segment(Point a,Point b,Point c,Point d){
    double c1 = Cross(b-a,c-a), c2 = Cross(b-a,d-a);
    double d1 = Cross(d-c,a-c), d2 = Cross(d-c, b-c);
    return sgn(c1)*sgn(c2) < 0 && sgn(d1)*sgn(d2) < 0;
}

int Point_in_polygon(Point pt,Point *p,int n){
    for(int i=0;i<n;i++){
        if(p[i] == pt) return 3;                // 3：点在多边形Point *p  
    }
    for(int i=0;i<n;i++){
        Line v = Line(p[i],p[(i+1)%n]);
        if(Point_on_seg(pt,v)) return 2;      // 2：点在多边形的边上
    }
    int num = 0;
    for(int i=0;i<n;i++){
        int j = (i+1)%n;
        int c = sgn(Cross(pt-p[j],p[i]-p[j]));
        int u = sgn(p[i].y-pt.y);
        int v = sgn(p[j].y-pt.y);
        if(c>0 && u<0 && v>=0) num++;
        if(c<0 && u>=0 && v<0) num--;
    }
    return num != 0;                            // 1：点在内部; 2：点在外部
}

double Polygon_area(Point *p,int n){
    double area = 0;
    for(int i=0;i<n;i++)
        area += Cross(p[i],p[(i+1)%n]);
    return area/2;
}

Point Polygon_center(Point *p,int n){
    Point ans(0,0);
    if(Polygon_area(p,n) == 0) return ans;
    for(int i=0;i<n;i++)
        ans = ans + (p[i]+p[(i + 1) % n]) * Cross(p[i],p[(i + 1) % n]);
    return ans/Polygon_area(p,n)/6;
}