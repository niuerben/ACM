#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n, a[N];

struct Node {
    int l, r;
    int state;  // 0: 初次访问，1: 已访问左子树，2: 已访问右子树
    int ret;    // 当前区间[l, r]的最大值
};

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    stack<Node> stk;
    vector<vector<int>> result_map(n+1,vector<int>(n+1,0));

    // 入栈初始状态
    stk.push({1, n, 0, 0});
    while (!stk.empty()) {
        Node &cur = stk.top();

        if (cur.l == cur.r) {
            cur.ret = a[cur.l];
            result_map[cur.l][cur.r] = cur.ret;
            stk.pop();
            continue;
        }

        int mid = (cur.l + cur.r) >> 1;

        if (cur.state == 0) {
            // 先处理左子区间
            cur.state = 1;
            stk.push({cur.l, mid, 0, 0});
        } else if (cur.state == 1) {
            // 然后处理右子区间
            cur.state = 2;
            stk.push({mid + 1, cur.r, 0, 0});
        } else {
            // 左右子树都处理完，合并结果
            int left_val = result_map[cur.l][mid];
            int right_val = result_map[mid+1][cur.r];
            cur.ret = max(left_val, right_val);
            result_map[cur.l][cur.r] = cur.ret;
            stk.pop();
        }
    }

    // 输出最终结果
    cout << result_map[1][n] << endl;

    return 0;
}
