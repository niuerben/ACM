#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,s,ans,idx;

vector<string> mp;

struct Name{
    vector<int> strlib;
    int start=0;
    int end=-1;
}name[N];

signed main() {
    int q;cin>>n>>q;
    while(q--){
        int op,p;
        cin>>op>>p;
        if(op==1){
            //  Replace the string of PC p with the string of the server.
            
            name[p].start = name[p].end+1;
            for(int i=name[0].start;i<=name[0].end;i++){
                name[p].end++;
                name[p].strlib.push_back(name[0].strlib[i]);
            }

        }
        
        else if(op==2){
            // Append string s to the end of the string of PC p.

            string s;
            cin>>s;
            mp.push_back(s);
            name[p].strlib.push_back(idx);
            name[p].end++;
            idx++;
        }

        else{
            // Replace the string of the server with the string of PC p.

            name[0].start = name[0].end+1;
            for(int i=name[p].start;i<=name[p].end;i++){
                name[0].end++;
                name[0].strlib.push_back(name[p].strlib[i]);
            }
        }
    }
    
    for(int i=name[0].start;i<=name[0].end;i++){
        int strID = name[0].strlib[i];
        cout<<mp[strID];
    }
    return 0;
}
