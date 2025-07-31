#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m,ans;

bool isOp(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int eval(int x,int y,char op){
    if(op=='+') return x+y;
    else if(op=='-') return x-y;
    else if(op=='*') return x*y;
    else if(op=='/') return x/y;
}

signed main() {
    string exp;
    cin>>exp;
    int cur = 0;
    stack<int> stkDigit;
    queue<char> stkOp;
    
    for(int i=0;i<exp.size();i++){
        if(isdigit(exp[i])) cur = cur*10+(exp[i]-'0');

        else if(exp[i]=='.'){
            stkDigit.push(cur);
            cur = 0;
        }

        else if(isOp(exp[i])) {
            stkOp.push(exp[i]);
            if(!isOp(exp[i+1])) {
                while(stkOp.size()){
                    int num1 = stkDigit.top();
                    stkDigit.pop();
                    int num2 = stkDigit.top();
                    stkDigit.pop();
                    char op = stkOp.front();
                    stkOp.pop();
                    stkDigit.push(eval(num2,num1,op));
                }
            }
        }
        else if(exp[i]=='@') {
            cout << stkDigit.top();
            break;
        }
    }
    return 0;
}


/*
Sample Input 1:
3.5.2.-*7.+@
Sample Output 1:
16

Sample Input 1:
10.28.30./*7.-@
Sample Output 1:
-7
*/