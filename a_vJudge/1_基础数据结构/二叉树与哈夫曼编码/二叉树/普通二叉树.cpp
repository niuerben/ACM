#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10,inf = 1e9;
int n,m,idx = 1;

struct Node{
    int val;
    int left=0;
    int right=0;
    int size = 0;
    bool isInit = false;
};
Node nodes[N];

int LowerX(int x,int cur){

if(!cur) return 0;
    int leftI = nodes[cur].left;
    int rightI = nodes[cur].right;
    if(x > nodes[rightI].val) return LowerX(x,rightI)+1;
    
    else return LowerX(x,leftI)+1;

}

int queryrk(int x, int cur)
{
    int leftI = nodes[cur].left;
    int rightI = nodes[cur].right;
	//如果左子树大小加上当前的数的多少恰好>=k，说明我们找到答案了 
	if(nodes[leftI].size + 1 == x)
        return nodes[cur].val;    //直接返回权值 

	//如果左子树大小>=rk了，就说明答案在左子树里 
    if(nodes[leftI].size + 1 >= x)
		return queryrk(x,leftI);//查左子树 
	
	//否则就查右子树，同时减去当前节点的次数与左子树的大小 
    else return queryrk(x-nodes[leftI].size-1,rightI);
}

void findLowerX(int x,int cur,int& ma){
    if(!cur) return;
    int leftI = nodes[cur].left;
    int rightI = nodes[cur].right;

    if(nodes[cur].val < x) ma = max(ma,nodes[cur].val);
    findLowerX(x,rightI,ma);
    if(nodes[rightI].val < x) {
        findLowerX(x,leftI,ma);
    }
}

void findUpperX(int x,int cur,int& mi){
    if(!cur) return;
    int leftI = nodes[cur].left;
    int rightI = nodes[cur].right;


    if(nodes[cur].val > x) {
        mi = min(mi,nodes[cur].val);
    }
    if(nodes[leftI].val > x) {
        findUpperX(x,leftI,mi);
    }
    findUpperX(x,rightI,mi);
}

void Insert(int x,int cur){
    nodes[cur].size++;
    if(nodes[cur].isInit == false){
        nodes[cur].val = x;
        nodes[cur].isInit = true;
        return;
    }

    // 分配左右节点
    int leftI = nodes[cur].left;
    int rightI = nodes[cur].right;
    if(leftI == false) nodes[cur].left = ++idx;
    if(rightI == false) nodes[cur].right = ++idx;

    if(x > nodes[cur].val) 
        Insert(x, nodes[cur].right);
    
    else Insert(x,nodes[cur].left);
}



signed main() {
    int q;cin>>q;
    while(q--){
        int op;cin>>op;
        int x;cin>>x;
        if(op==1) cout<<LowerX(x,1)<<'\n';
        else if(op==2){
            cout<<queryrk(x,1)<<'\n';
        }
        else if(op==3) {
            int ma = -__INT32_MAX__;
            findLowerX(x,1,ma);
            cout<<ma<<'\n';
        }
        else if(op==4) {
            int mi = __INT32_MAX__;
            findUpperX(x,1,mi);
            cout<<mi<<'\n';
        }
        else if(op==5) Insert(x,1);
    }
    return 0;

}

