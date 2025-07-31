#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3+10, inf = 1e9;
int n,m,col,row,d,rd;
char a[N][N];

int cnt = 0;
int cntQ = 0;
int queen(int limit,int col,int left,int right){
    if(limit == col){
        return 1;
    }
    
    // 禁止放皇后的位置
    int ban = col | left | right;
    // 可以放皇后的位置
    int candidate = ~ban & limit;

    int place = 0;
    int ans = 0;
    while(candidate != 0){
        // 获取最右侧的1
        /*
            candidate:          0 0 1 1 0
            place:              0 0 0 1 0
            candidate ^ place:  0 0 1 0 0
        */
        place = candidate & (-candidate);
        candidate ^= place;

        // left模拟左对角线状态
        /*
            left         0 0 0 1 0
            left >> 1    0 0 1 0 0
        */
        ans += queen(limit, col|place, (left|place)>>1, (right|place)<<1 );
    }
    return ans;
}

signed main() {
    cin>>n;
    auto start = std::chrono::high_resolution_clock::now();
    // 待测代码
    // 皇后位置的最大上限
    /*
    limit:  1 1 1 1 1
    */
    int limit = (1<<n)-1;
    printf("%lld皇后问题的答案为:%lld\n",n,queen(limit, 0,0,0));
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "耗时: " << (double)duration.count()/1000000 << " 秒" << std::endl;
    return 0;
}

/*
16皇后问题只有在位运算可以10秒内跑完
*/