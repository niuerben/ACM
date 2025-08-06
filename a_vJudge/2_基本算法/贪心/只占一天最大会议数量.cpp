#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m,ans;

struct arr{
    int l,r;
};
arr a[N];

signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;
    
    sort(a+1,a+1+n,[](arr a,arr b){
        return a.l == b.l ? a.r<b.r : a.l < b.l;
    });

    int minDay = a[1].l;
    int maxDay = 0;
    for(int i=1;i<=n;i++) maxDay=max(maxDay,a[i].r);

    int j = 1;
    priority_queue<int,vector<int>,greater<> > heap; // 创建小根堆

    for(int day=minDay;day<=maxDay;day++){
        while(j<=n && a[j].l==day){ // 当日开始的会议全部入堆
            heap.push(a[j++].r);
        }

        while(heap.size() && heap.top() < day) heap.pop(); // 删除过期会议
        
        if(heap.size() && heap.top() >= day){ // 参与最新会议
            heap.pop();
            ans++;
        }


    }
    cout<<ans;

    return 0;
}
    
/*
Sample Input 1:
4
1 3
1 4
1 5
2 3
Sample Output 1:
4
*/