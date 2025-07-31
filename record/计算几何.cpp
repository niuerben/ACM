#include<bits/stdc++.h>
using namespace std;
#define int long long

#include "计算几何_点.h"

signed main(){
    /*cout<<sgn(1)<<" "<<sgn(-1)<<" "<<sgn(0)<<'\n';
    Point a(1,1),b(2,2);
    printf("a = ( %lf, %lf ), b = ( %lf, %lf )\n",a.x,a.y,b.x,b.y);
    printf("|ab| = %lf\n",Distance(a,b));
    Point c = a+b;
    printf("a + b = ( %lf, %lf )\n",c.x,c.y);
    Point d = a-b;
    printf("a - b = ( %lf, %lf )\n",d.x,d.y);
    printf("a * b = %lf\n",Dot(a,b));
    printf("|a + c| = %lf\n",Len(c));

    printf("<a, a-b> = %lfpi\n",Angle(a,d)/pi);
    printf("<a, a-b> = %lf°\n",Angle(a,d)*180/pi);
    
    Point e = Rotate(a,pi/2);
    Point f = Rotate(a,-pi/2);
    Point g = Normal(a);
    printf("a 逆时针旋转90° = ( %lf, %lf )\n",e.x,e.y);
    printf("a 顺时针旋转90° = ( %lf, %lf )\n",f.x,f.y);
    printf("a 的单位法向量 = ( %lf, %lf )\n",g.x,g.y);
    
    if(Parallel(a,c))
        printf("a // b \n");
    else
        printf("<a, b> = %lfpi\n",Angle(a,b)/pi);*/

    

    /*Point p1(0,0),p2(1,1);
    Line line(p1,p2);
    Point p3(2,2);
    if(Point_line_relation(p3,line) == 0)
        printf("点p3在直线line上\n");
    else if(Point_line_relation(p3,line) == 1)
        printf("点p3在直线line左侧\n");
    else
        printf("点p3在直线line右侧\n");
    
    if(Point_on_seg(p2,Line(p1,p3))) 
        printf("p2在线段p1-p3上\n");
    if(!Point_on_seg(p3,line))
        printf("p3不在线段line上\n");
    
    Point p4(0,1);
    printf("点p4与直线line的距离：%lf\n",Dis_point_line(p4,line));
    Point poj_p4_line = Point_line_proj(p4,line);
    printf("点p4到line上的投影点为( %lf, %lf )\n",poj_p4_line.x,poj_p4_line.y);
    Point p4s = Point_line_symmetry(p4,line);
    printf("点p4对直线line的对称点为( %lf, %lf )\n",p4s.x,p4s.y);

    printf("点p3到线段line的距离为( %lf, %lf )\n",Dis_point_seg(p3,line));

    Line line2(p2,p3);
    Line line3(p2,p4);
    Line line4(Point(1,0),Point(2,1));
    
    if(Line_relation(line,line2) == 1)
        printf("直线line与直线line2重合\n");
    if(Line_relation(line,line3) == 2)
        printf("直线line与直线line3相交\n");
    if(Line_relation(line,line4) == 0)
        printf("直线line与直线line4平行\n");

    if(!Cross_segment(p1,p2,p3,p4))
        printf("\n");*/
    


    /*Point polygon[4]={{-1,-1},{-1,1},{1,1},{1,-1}};
    // for(int i=0;i<4;i++){
    //     cin>>polygon[i].x>>polygon[i].y;
    // }
    Point p(0,0);
    // cin>>p.x>>p.y;
    if(Point_in_polygon(p,polygon,4) == 1)
        printf("点p在多边形polygon内部\n");
    else if(Point_in_polygon(p,polygon,4) == 0)
        printf("点p在多边形polygon外部\n");
    else if(Point_in_polygon(p,polygon,4) == 2)
        printf("点p在多边形polygon边上\n");
    else if(Point_in_polygon(p,polygon,4) == 3)
        printf("点p在多边形polygon顶点上\n");
    
    printf("多边形polygon的面积为：%lf\n",Polygon_area(polygon,4));

    Point g = Polygon_center(polygon,4);
    printf("多边形polygon的重心为：( %lf, %lf )\n",g.x,g.y);*/



    return 0;
}