#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

string code;

int where = code.size();
string f(int now){
    string path;
    int cur = 0;
    for(int i=now;i<=code.size();i++){
        // 追加当前字符
        if(isalpha(code[i])) path+=code[i];

        // 计算倍数
        else if(isdigit(code[i])){
            cur = cur*10 + code[i]-'0';
        }

        // 解压
        else if(code[i] == '['){
            string addCode = f(i+1);
            for(int i=1;i<=cur;i++) path+=addCode;
            cur = 0;
            // 跳转至where
            i = where;
        }
        
        // 结束解压
        else if(i == code.size() || code[i] == ']'){
            where = i;
            return path;
        }
    }
}

signed main() {
    cin>>code;

    cout << f(0);
    return 0;
}
    