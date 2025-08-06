#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define Inf 1<<31-1
struct node {
	double x;
	double y;
	int id;//点的编号
};
struct node point[200005];
int temp[300005];
int a = 2147483647, b = 2147483647, ans = 2147483647;
double dis(node a, node b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool cmp1(node a, node b)
{
	if (a.x == b.x)return a.y < b.y;
	return a.x < b.x;
}//第一个排序是按照x坐标升序，排序以后才好分左右平面 
bool cmp2(int a, int b)
{
	return point[a].y < point[b].y;
}//第二个排序是选择中间的点，按y坐标升序排列
 
 
void Update(int new_a, int new_b, int new_ans)
{
	if (new_a > new_b) swap(new_a, new_b);
	if (new_ans == ans)
	{
		if (a > new_a || a == new_a && b > new_b)
		{
			a = new_a;
			b = new_b;
		}
	}
	else { a = new_a; b = new_b; ans = new_ans; }
}
void MiniDistance(int left, int right)
{
	if (left == right)return;//如果自己和自己的距离最近，则距离为0，应该返回 
	if (left + 1 == right)
	{
		//获取距离
		int cur = dis(point[left], point[right]);
		//如果当前距离更小，则更新一下答案
		if (ans >= cur) Update(point[left].id, point[right].id, cur);
		return;
	}
	int mid = (left + right) >> 1;//如果中间还有其他点，那就再中间分开。 
	MiniDistance(mid, right);//找右边的最小距离 
	MiniDistance(left, mid - 1);//找左边的最小距离 
	int k = 0;
	for (int i = left; i <= right; i++)
	{
		if (fabs(point[mid].x - point[i].x) <= ans)
		{
			temp[++k] = i;
		}
	}//有可能在两个平面中间还有其他的更小距离 这个就是按照x坐标找可能出现的点 
	sort(temp + 1, temp + k + 1, cmp2);//按这些点的y坐标升序排列
	//线性扫描，找这些点的最小距离 
	for (int i = 1; i <= k; i++)
	{
		for (int j = i + 1; j <= k && point[temp[j]].y - point[temp[i]].y <= ans; j++)//注意第二个判断条件
		{
			if (ans >= dis(point[temp[i]], point[temp[j]]))
			{
				int new_distance = dis(point[temp[i]], point[temp[j]]);
				Update(point[temp[i]].id, point[temp[j]].id, new_distance);
			}
		}
	}
	return;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> point[i].x >> point[i].y;
		//点的序号
		point[i].id = i - 1;
	}
	//按横坐标升序排列
	sort(point + 1, point + n + 1, cmp1);
	MiniDistance(1, n);
	printf("%.4f",sqrt(dis(point[a+1],point[b+1])));
	return 0;
}