#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;
int n,m;

// 0变1，1变0
int flip(int n){
    return n^1;
}

// 非负数返回1，负数返回0
int sign(int n){
    // 将n转化为无符号数，再右移，即可实现无符号右移
    unsigned int nn = (unsigned) n;
    return flip(nn>>31);
}

int getMax1(int a,int b){
    int c = a-b;
    int returnA = sign(c);
    int returnB = flip(returnA);

    return returnA*a + returnB*b; 
}

int getMax2(int a,int b){
    int c = a-b;
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);
    // 判断AB是否不同，不同为1，相同为0
    int diffAB = sa^sb;
    int sameAB = flip(diffAB);

    // 如果AB异号并且a非负，或者AB同号并且c非负，则返回A
    int returnA = diffAB*sa + sameAB*sc;
    int returnB = flip(returnA);

    return returnA*a + returnB*b;
}

signed main() {

    // 2 不用比较操作返回最大值
    int a = 114;
    int b = -514;

    // 有溢出风险
    cout << getMax1(a,b) << endl;

    // 无溢出风险
    cout << getMax2(a,b) << endl;

    return 0;
}

// 2 不用比较操作返回最大值