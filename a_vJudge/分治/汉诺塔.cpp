
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Hannoi(int a, int b, int n)//起点，终点，盘子个数
{
    // TODO: 处理递归终点，并递归输出移动过程
    if(n==0) return;
    Hannoi(a,3-a-b,n-1);
    printf("Move disk %d from %c to %c\n",n,'A'+a,'A'+b);
    Hannoi(3-a-b,b,n-1);
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
        Hannoi(0, 2, n); //从0号柱子转移n个盘子到2号柱子
    return 0;
}