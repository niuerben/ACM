#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,e[N],ne[N],h,idx;

struct Node{
    char color;
    int cnt;
};

Node strs[N];
int len;

signed main() {
    string s;
    cin>>s;
    list<Node> ls; 
    for(int i=0;i<s.size();i++){
        strs[i].cnt = 1;
        if(i>0 && s[i]==s[i-1]) strs[i].cnt = strs[i-1].cnt+1;
        ls.push_back({s[i],strs[i].cnt});
        len++;
    }

    cin>>m;
    while(m--){
        char op1,op2;
        cin>>op1>>op2;
        auto it = ls.begin();
        while(it->color != op1) it++;
        it++;
        int t;
        ls.insert(it,{op2,3});
    }

    for(auto i:ls) cout<<i.color<<" "<<i.cnt<<endl;
    return 0;
}
    