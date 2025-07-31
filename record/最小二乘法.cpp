#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10;
double p[N],t[N],p2[N],pt[N];
double sum_t,sum_p,sum_p2,sum_pt;

class Func{
private:
    double a,b,c;
public:
    Func(double aa,double bb,double cc):a(aa),b(bb),c(cc){}
    friend double calX(const Func &a, const Func &b);
    friend double calY(const Func &a, const Func &b);
};

double calX(const Func &a,const Func &b){
    return (a.c*b.b-a.b*b.c)/(a.a*b.b-a.b*b.a);
}

double calY(const Func &a,const Func &b){
    return (a.a*b.c-a.c*b.a)/(a.a*b.b-a.b*b.a);
}

signed main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>t[i];
        sum_t += t[i];
        sum_p += p[i];
        sum_p2 += p[i]*p[i];
        sum_pt += p[i]*t[i];
    }

    Func f1(sum_p2, sum_p, sum_pt);
    Func f2(sum_p, n, sum_t);
    double a = calX(f1,f2);
    double b = calY(f1,f2);

    printf("sum_t = %lf, sum_p = %lf, sum_p2 = %lf, sum_pt = %lf\n",sum_t,sum_p,sum_p2,sum_pt);
    
    printf("θ = %lfp%+lf\n其中a = %lf, b = %lf\n",a,b,a,b);
    return 0;
}