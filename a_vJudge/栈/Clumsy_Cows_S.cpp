#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m,ans;

signed main() {
    
    string parentheses;
    cin>>parentheses;
    stack<char> stkP;
    for(int i=0;i<parentheses.size();i++){
        if(parentheses[i]=='('){
            stkP.push('(');
        }
        else {
            if(stkP.size() && stkP.top()=='(')
                stkP.pop();
            else stkP.push(')');
        }
    }

    int cnt1=0,cnt2=0;
    while(stkP.size()){
        
        if(stkP.top()=='(') cnt1++;
        if(stkP.top()==')') cnt2++;
        stkP.pop();
    }
    
    cout<<(cnt1+1)/2+(cnt2+1)/2;
    return 0;
}

/*
Sameple Input 1:
(()))))(((
Sample Output 1:
4
*/
    