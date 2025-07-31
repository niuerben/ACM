#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,inf = 1e9;
int n,m,Next[N];
string s1,s2;

void init(string s){
    
    Next[0] = -1;
    Next[1] = 0;
    int i = 2;
    int cn = 0;
    while(i<m){
        // 匹配到就向右移动
        if(s[i-1] == s[cn]){
            Next[i++] = ++cn;
        }
        // 匹配不到就往前跳
        else if(cn>0){
            cn = Next[cn];
        }
        else{
            Next[i++] = 0;
        }
    }
}

int kmp(string s1,string s2){

    int i=0,j=0;
    while(i<n && j<m){
        // 匹配到就同时右移
        if(s1[i]==s2[j]){
            i++;
            j++;
        }
        // 匹配不到往前跳
        else if(j>0){
            j = Next[j];
        }
        // 跳到尽头母串往后走
        else{
            i++;
        }
    }
    
    return j==m ? i-j : -1;
}

signed main() {
    cin>>s1>>s2;
    n = s1.size();
    m = s2.size();

    // 初始化Next数组
    init(s2);

    // 计算第一个匹配点
    cout << kmp(s1,s2);



    return 0;
}
    