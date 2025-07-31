#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;

// 方法一：顺序表
int n,m,k,ans=inf,ansL,ansR,cnt,mp[N];
struct Node{
    int val,i,j;
    bool operator<(const Node& b)const{
        return val == b.val ? i<b.i : val < b.val;
    }
};

signed main() {
    cin>>k;
    vector<vector<Node>> v(k+1,vector<Node>());
    for(int i=1;i<=k;i++) {
        int m;
        cin>>m;
        while(m--){
            int val;
            cin>>val;
            int j = v[i].size();
            v[i].push_back({val,i,j});
        }
    }

    set<Node> st;
    Node Max,Min;
    for(int i=1;i<=k;i++) st.insert(v[i][0]);

    while(st.size() == k){
        Min = *st.begin();
        Max = *st.rbegin();
        
        if(Max.val-Min.val+1 < ans){
            ans = Max.val-Min.val+1;
            ansL = Min.val;
            ansR = Max.val;
        }

        st.erase(st.begin());
        if(Min.j+1 < v[Min.i].size()) st.insert(v[Min.i][Min.j+1]);
    }

    cout<<ansL<<" "<<ansR;    
    return 0;
}
    


// 方法二：双指针
/*int n,m,k,ans=inf,ansL,ansR,cnt,mp[N];

struct Arr{
    int val,index;
};
Arr a[N];

signed main() {
    cin>>k;
    for(int i=1;i<=k;i++) {
        int m;
        cin>>m;
        while(m--){
            cin>>a[++n].val;
            a[n].index = i;
        }
    }

    sort(a+1,a+1+n,[](Arr a,Arr b){
        return a.val == b.val ? a.index < b.index : a.val < b.val;
    });

    int j=0;
    for(int i=1;i<=n;i++){
        while(j<n && cnt<k){ // 前驱指针更新数据
            j++;
            if(!mp[a[j].index]) cnt++;
            mp[a[j].index]++;
        }

        if(j-i+1 < ans && cnt==k){ // 更新答案
            ans = a[j].val-a[i].val+1;
            ansL =  a[i].val;
            ansR =  a[j].val;
        }

        mp[a[i].index]--; // 后动指针复原数据
        if(!mp[a[i].index]) cnt--;
    }
    cout<<ansL<<" "<<ansR;
    return 0;
}*/

