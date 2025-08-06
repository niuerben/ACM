#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
int n,m;

string formular;

int where = formular.size();
map<string,int> f(int now){
    map<string,int> curLib;
    string cur;
    map<string,int> addMap;
    int num = 0;
    for(int i=now;i<=formular.size();i++){
        // 获取原子名称
        if(isupper(formular[i])) {
            cur = formular[i];
            if(i+1==formular.size() || !islower(formular[i+1])) {
                curLib[cur]++;
            }
        }
        else if(islower(formular[i])){
            cur += formular[i];
            if(i+1==formular.size() || !islower(formular[i+1])) {
                curLib[cur]++;
            }
        
        }

        // 解压
        else if(formular[i] == '('){
            addMap = f(i+1);
            i = where;
        }

        else if(i == formular.size() || formular[i] == ')'){
            where = i;
            return curLib;
        }

        // 计算括号内原子个数
        else if(isdigit(formular[i])){
            num = num*10 + formular[i]-'0';
            if(i+1==formular.size() || !isdigit(formular[i+1])){
                for(auto [key,val]:addMap){
                    curLib[key]+=val*num;
                }
                num = 0;
            }
        }
        
    }
}

signed main() {
    cin>>formular;
    
    map<string,int> mp = f(0);

    for(auto [key,val]:mp){
        cout << key << " " << val << endl;
    }
    return 0;
}
/*
本题依然是嵌套递归问题，利用where跳转至括号外继续解析。此题亮点在于递归函数返回值是有序表，巧妙继承了大量数据。
*/