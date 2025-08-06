#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,k,m,ans;

struct Project{
    int capital,profit;
};
Project pj[N];

signed main() {
    cin>>m>>k;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>pj[i].profit>>pj[i].capital;

    sort(pj+1,pj+1+n,[](Project a,Project b){
        return a.capital == b.capital ? a.profit < b.profit : a.capital < b.capital;
    });

    priority_queue<int> heap;
    int j = 1;
    ans = m;
    for(int i=1;i<=k;i++){
        while(j<=n && pj[j].capital <= ans) heap.push(pj[j++].profit);

        if(heap.size()){
            ans += heap.top();
            heap.pop();
        }
    }
    cout<<ans;

    return 0;
}


/*
Sample Input 1:
1 3
3
1 5
6 3
2 1
Sample Output 1:
10

Sample Input 2:
1 3
4
1 5
6 4
5 4
2 1  
Sample Output 2:
3 // 哎，资本
*/