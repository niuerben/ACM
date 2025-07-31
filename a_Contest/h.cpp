#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,x0,y0,ans;

struct Point{
    int x;
    int y;
    Point operator - (Point B){return Point(x-B.x,y-B.y);}
};
Point p0;
double Distance(Point A,Point B){return hypot(A.x-B.x,A.y-B.y);};



// 判断象限
int Quadrant(Point a){
    if(a.x>0&&a.y>=0)  return 1;
    if(a.x<=0&&a.y>0)  return 2;
    if(a.x<0&&a.y<=0)  return 3;
    if(a.x>=0&&a.y<0)  return 4;
}

signed main() {
    int t;cin>>t;
    while(t--){
        cin>>n>>x0>>y0;
        double len = 0;
        vector<Point> p(n+1);
        p0 = {x0,y0};
        for(int i=1;i<=n;i++) {
            cin>>p[i].x>>p[i].y;
            len = max(len,Distance(p[0],p[i]));
        }

        vector<Point> p2;
        for(int i=1;i<=n;i++){
            if(Distance(p[0],p[i]) == len) p2.push_back(p[i]);
        }

        // sort(p2.begin(),p2.end(),cmp3);
        
        int p2Len = p2.size();
        int len1 = Distance(p0,p[p2Len-2]);
        int len2 = Distance(p0,p[p2Len-1]);
        cout<<acos((len1*len1+len2*len2-2*len1*len2)/(2*len1*len2)) << '\n';
    }
    
    return 0;
}
