#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

int precedence(char c){
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    return 0;
}

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}


string inToPost(const string &exp){
    string res;
    stack<char> stk;
    for(auto c:exp){
        if(isspace(c)) continue;
        else if(isdigit(c)){
            res += c;
        }
        else if(c == '('){
            stk.push(c); 
        }
        else if(c == ')'){
            while(stk.size() && stk.top() != '('){
                res += " ";
                res += stk.top();
                stk.pop();
            }
            
            stk.pop(); // pop '('
        }
        else if(isOperator(c)){
            res += " ";
            while(stk.size() && precedence(stk.top()) >= precedence(c)){
                res += stk.top();
                res += " ";
                stk.pop();
            }
            stk.push(c);
        }
    }

    while(stk.size()) {
        res += " ";
        res += stk.top();
        stk.pop();
    }
    
    return res;
}

string inToPre(string s) {
    reverse(s.begin(), s.end());
    for (char &c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    stack<char> stk;
    string res;
    for (char c : s) {
        if (isspace(c)) continue;
        if (isdigit(c)) {
            res += c;
        } 
        else if (c == '(') {
            stk.push(c);
        } 
        else if (c == ')') {
            while (!stk.empty() && stk.top() != '(') {
                res += " ";
                res += stk.top(); stk.pop();
            }
            if (!stk.empty()) stk.pop();
        } 
        else if (isOperator(c)) {
            while (!stk.empty() && precedence(stk.top()) > precedence(c)) {
                res += " ";
                res += stk.top(); stk.pop();
            }
            stk.push(c);
            res += " ";
        }
    }
    while (!stk.empty()) {
        res += " ";
        res += stk.top(); stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

signed main() {
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<inToPre(s)<<'\n';
        cout<<inToPost(s)<<'\n';
        cout<<'\n';
    }
    return 0;
}

/*
Sample Input 1:
2
4+2*3-10/5
12+3*5+(2+10)*5 

Sample Output 1:
- + 4 * 2 3 / 10 5
4 2 3 * + 10 5 / -

+ + 12 * 3 5 * + 2 10 5
12 3 5 * + 2 10 + 5 * +
*/