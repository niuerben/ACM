#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9;
int n,m,ans,mpWord[N];

signed main() {
    cin>>m>>n;
    queue<int> queueWord;
    for(int i=1;i<=n;i++){
        int word;
        cin>>word;
        if(mpWord[word]) continue;
        ans++; 
        mpWord[word]=1;
        if(queueWord.size() < m){ queueWord.push(word);}
        else{
            mpWord[queueWord.front()] = 0;
            queueWord.pop();
            queueWord.push(word);
        }
    }
    cout<<ans;
    return 0;
}
    