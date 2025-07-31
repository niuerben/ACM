#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

string expr;

int cal(int a,int b,char op){
    if(op == '+') return a+b;
    if(op == '-') return a-b;
    if(op == '*') return a*b;
    if(op == '/') return a/b;
}

bool isOp(char op){
    return op == '+' || op == '-' || op == '*' || op == '/';
}

int where = expr.size();
int f(int now){
    int cur = 0;
    stack<int> numStk;
    stack<char> opStk;
    for(int i=now;i<=expr.size();i++){
        // 计算数值
        if(isdigit(expr[i])) {
            cur = cur*10+expr[i]-'0';
        }
        else{
            numStk.push(cur);
            if(opStk.size()) {
                char op = opStk.top();
                if(op == '*' || op == '/') {
                    int a = numStk.top();numStk.pop();
                    int b = numStk.top();numStk.pop();
                    int c = cal(b,a,op);
                    numStk.push(c);
                    opStk.pop();
                }
            }

            // 压入符号 
            if(isOp(expr[i])){
                opStk.push(expr[i]);
                cur = 0;
            }

            // 解压
            else if(expr[i] == '('){
                cur = f(i+1);   
                // 跳转至where
                i = where;
            }
            
            // 结束解压
            else if(i == expr.size() || expr[i] == ')'){
                where = i;
                int res = 0;     
                while(numStk.size()){
                    char op = '+';
                    if(opStk.size()){
                        op = opStk.top();
                        opStk.pop();
                    }
                    
                    int a = numStk.top();numStk.pop();
                    res = cal(res,a,op);   
                }
                return res;
            }
        }
        
    }
    
}

signed main() {
    cin>>expr;

    cout << f(0);
    return 0;
}
/*
递归解决嵌套问题：利用递归优先处理括号内信息，利用where知道递归结束后需要从哪里继续解析
*/