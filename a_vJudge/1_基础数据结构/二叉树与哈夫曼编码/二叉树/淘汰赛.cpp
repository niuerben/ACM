#include<iostream>
#include<cstring>
#include<algorithm> //比赛的时候闲的没事打了一堆头文件
#include<cmath>
#include<iomanip> 
using namespace std;
struct Node{ 
 	int power,id;  //power——能力值，id——国家序号
}; 
Node maxt(Node a,Node b){  //返回两个结构体里能力值更大的那个
	return a.power>b.power ? a : b;
}
Node mint(Node a,Node b){ //返回两个结构体里能力值更小的那个
    return a.power < b.power ? a : b;
}
Node a[150],tree[600];  //a——数据，tree——线段树（一般为了防爆，线段树都是开数组的4倍空间）
void build(int node,int start,int end){ //建树函数
	if(start==end){  //叶节点，返回
		tree[node] = a[start];
		return;
	}
	int lnode=node*2;  //左右子树、中点
	int rnode=node*2+1;
	int mid = lnode+rnode>>1;
	build(lnode,start,mid);  //两边递归建树
	build(rnode,mid+1,end);
	tree[node]=maxt(tree[lnode],tree[rnode])  //父节点是左右子节点里更大的;
}
int main(){
	int n;  //输入
	cin>>n;
	for(int i=1;i<=(1<<n);i++){  //1<<n就是2的n次方啦！（这样比pow函数更快哦！）
		cin>>a[i].power;//输入，赋值，很简单
		a[i].id=i;
	}
	build(1,1,(1<<n)); //建树（根节点是1，整棵树从1到2的n次方）
	cout << mint(tree[2],tree[3]).id; //从tree[2],tree[3]里找个小的就是亚军，输出它的序号
	return 0;
}