#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;


signed main() {
    string s;
    while(cin>>s){
        unordered_map<char,int> mp;
        priority_queue<int,vector<int>,greater<> > q;
        int ans = 0;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        for(auto [key,val]:mp){
            q.push(val);
        }

        if(q.size()==1) cout<<q.top() << '\n';
        else{
            while(q.size() > 1){
                int a = q.top();q.pop();
                int b = q.top();q.pop();
    
                q.push(a+b);
                ans += a+b;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}

/*
哈夫曼编码就是合并果子。每次合并频率最低的两个节点，合并次数等于编码长度。
*/