#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
struct Node
{
    int mat[2][2];
    Node(){}
    Node(int a_, int b_, int c_, int d_)
    {
        mat[0][0] = a_;
        mat[0][1] = b_;
        mat[1][0] = c_;
        mat[1][1] = d_;
    }
    Node operator*(const Node &y)
    {
        // TODO: 矩阵乘法，注意取模
        Node res(0,0,0,0);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k]*y.mat[k][j]) % mod;
                }
            }
        }

        return res;
    }
};
Node Pow(Node a, int n)
{
    // TODO: 矩阵的快速幂
    Node res(1,1,1,0);
    Node base(1,1,1,0);
    while(n > 0){
        if(n&1) res = res * base; 
        base = base * base;
        n>>=1;
    }
    return res;
}
signed main()
{
    int n;
    
    // 检验矩阵乘法
    // Node a(1,2,3,4),b(4,3,2,1),c(0,0,0,0);
    // c = a*b;
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<2;j++){
    //         cout<<c.mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    while(scanf("%lld", &n) != EOF)
    {
        // TODO: 初始化用于推导斐波那契数列的矩阵
        Node x(1,1,1,0);
        Node ans = Pow(x, n-2);
        // TODO: 输出矩阵中对应的斐波那契第n项
        printf("%lld\n",ans.mat[0][0]);
    }
    return 0;
}

/*
Sample Input1:
1
2
20
100000000
Sample Output1:
1
1
6765
908460138
*/