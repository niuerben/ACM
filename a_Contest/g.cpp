#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10,inf = 1e9;
int n, xx,yy;

const double pi_2 = acos(0);
const double pi = acos(-1.0);
const double eps = 1e-10;
// 点
struct Point{
    int x,y;
    Point(){}
    Point(int x,int y):x(x),y(y){}
    Point operator + (Point B){return Point(x+B.x,y+B.y);}
    Point operator - (Point B){return Point(x-B.x,y-B.y);}
    bool operator == (Point B){return x-B.x==0 && y-B.y==0;}
};
Point p0;
typedef Point Vector;
int Dot (Vector A,Vector B){return A.x*B.x+A.y*B.y;} // 点积
int Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;} // 叉积
int Len2(Point A,Point B){
    int dx = A.x-B.x;
    int dy = A.y-B.y;
    return dx*dx+dy*dy;
};
//判断象限
int Quadrant(Point a){
    if(a.x>0&&a.y>0)  return 1;
    else if(a.x<0&&a.y>0)  return 2;
    else if(a.x<0&&a.y<0)  return 3;
    else if(a.x>0&&a.y<0)  return 4;
    else return 0;
}

// 直线
struct Line{
    Point p1,p2;
    Line(){}
    Line(Point p1, Point p2):p1(p1),p2(p2){}
};
typedef Line Segment;
bool Point_on_seg(Point p, Line v){
    if(Cross(p-v.p1,v.p2-v.p1) == 0 && Dot(p-v.p1,p-v.p2) <= 0) return true;
    return false;
}

int Point_in_polygon(Point pt,vector<Point> p,int n){
    bool inside = true;
    for (int i = 1; i <= n && inside; ++i){
        int j = i%n+1;
        int dx = p[j].x-p[i].x, dy = p[j].y-p[i].y;
        int rx = p0.x-p[i].x, ry = p0.y-p[i].y;
        if (dx*ry - dy*rx < 0){
            inside = false; break; 
        }
    }
    return inside;
}

signed main() {
    int t;cin>>t;
    while(t--){
        cin>>n>>xx>>yy;
        int len = 0;
        vector<Point> p(n+1);
        p0 = {xx,yy};
        for(int i=1;i<=n;i++) {
            cin>>p[i].x>>p[i].y;
            len = max(len,Len2(p0,p[i]));
        }

        if(!Point_in_polygon(p0,p,n)){
            printf("%.15lf\n",pi*2);
        }
        else{
            vector<Point> p2;
            for(int i=1;i<=n;i++){
                if(Len2(p0,p[i]) == len) p2.push_back(p[i]);
            }
    
            int cnt = p2.size();
            vector<double> deg(cnt);
            vector<double> ap(cnt);
            double ans = 0;
            for(int i=0;i<cnt;i++){
                double dy = p2[i].y-p0.y;
                double dx = p2[i].x-p0.x;
    
                if(dx == 0){
                    if(dy>0) deg[i]=pi_2;
                    else if(dy<0) deg[i]=pi_2*3;
                    continue;
                }
                else if(dy == 0){
                    if(dx>0) deg[i]=0;
                    else if(dx<0) deg[i]=pi;
                }
                int q = Quadrant(Point(dx,dy));
                if(q == 1) deg[i]=atan(dy/dx);            
                else if(q==2) deg[i]=atan(dy/dx)+pi;
                else if(q==3) deg[i]=atan(dy/dx)+pi;
                else if(q==4) deg[i]=atan(dy/dx)+pi*2;
            }
    
            sort(deg.begin(),deg.end());
            for(int i=0;i<cnt-1;i++){
                ap[i]=deg[i+1]-deg[i];
                ans = max(ans,ap[i]) ;
            }
            ap[cnt-1]=pi_2*4-deg[cnt-1]+deg[0];
            ans = max(ans,ap[cnt-1]);
            printf("%.15lf\n",ans);
        }
        
    }
    
    return 0;
}
