#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 610, inf = 1e9, mod = 1e9+7;
int n,m,in[N],Count[N],sum,k,have;
struct Node{
    char v;
    int d;
};
vector<char> g[N];
string ans;
char u[N],v[N];
set<char> st;
void topsort(){
    sum=0;
    queue<Node> q;
    for(char i='A';i<='Z';i++) {
        if(!in[i] && Count[i]) {
            q.push({i,1});
        }
    }
    int dd = 0;
    while(q.size()){
        auto [u,d] = q.front(); q.pop();
        ans += u;
        sum++;
        // 稳定的拓扑排序：层数为n
        dd = max(dd,d);
        
        for(auto v:g[u]){
            in[v]--;
            if(!in[v]) q.push({v,d+1});
        }
    }
    
    if(dd==n){
        printf("Sorted sequence determined after %lld relations: ",k);
        cout<<ans<<".";
        exit(0);
    }
    if(sum!=have){
        printf("Inconsistency found after %lld relations.",k);
        exit(0);
    }
}

signed main() {
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        // 坚持用scanf，开头的空格跳过空白符
        scanf(" %c<%c", &u[i], &v[i]);  
        // 字符读入数组用string转
        // string str;
        // cin>>str;
        // u[i]=str[0];
        // v[i]=str[2];
        g[u[i]].push_back(v[i]);
        Count[u[i]] = true;
        Count[v[i]] = true;
        memset(in,0,sizeof in);
        for(int j=1;j<=i;j++) in[v[j]]++;
        k = i;
        ans = "";
        st.insert(u[i]);
        st.insert(v[i]);
        have = st.size();
        topsort();
    }

    cout<<"Sorted sequence cannot be determined.";
    return 0;
}
    