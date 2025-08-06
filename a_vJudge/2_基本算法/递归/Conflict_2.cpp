#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,s;
vector<string> ans;

struct Version{
    int pcID = -1;
    int version = -1;
};

struct Node{
    Version fa;
    string str;
};

struct PC{
    vector<Node> SL;
}pc[N];

signed main() {
    int q;
    cin>>n>>q;
    string emptyStr = "";

    while(q--){
        int op,p;
        cin>>op>>p;
        if(op==1){
            //  Replace the string of PC p with the string of the server.
            int cntP = pc[p].SL.size();
            int cnt0 = pc[0].SL.size();
            pc[p].SL.push_back({{0,cnt0-1},""});
        }
        
        else if(op==2){
            // Append string s to the end of the string of PC p.
            string s;
            cin>>s;
            int cnt = pc[p].SL.size();
            pc[p].SL.push_back({{p,cnt-1},s});
        }

        else{
            // Replace the string of the server with the string of PC p.
            int cntP = pc[p].SL.size();
            int cnt0 = pc[0].SL.size();
            pc[0].SL.push_back({{p,cntP-1},""});
        }
    }

    int cnt0 = pc[0].SL.size();
    Version cur ={0,cnt0-1};
    while(cur.pcID != -1 && cur.version != -1){

        int pcID = cur.pcID;
        int version = cur.version;
        ans.push_back(pc[pcID].SL[version].str);
        cur = pc[pcID].SL[version].fa;
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }
    return 0;
}
