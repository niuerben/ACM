#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e6+7;
int n,m,cnt;

vector<int> vec[N];

bool isQ(int i){
    return sqrt(i) == (int)sqrt(i);
}

bool prime(int x){
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}

// 判断加质因数能否成完全平方数
bool check(int x){
    for(int i=2;i<=x;i++){
        if(x%i==0 && prime(i)) vec[x].push_back(i);
    }

    for(int i=0;i<vec[x].size();i++){
        if(isQ(x+vec[x][i])) {
            // cout<<x<<" "<<vec[x][i]<<endl;
            return true;
        }
    }
    return false;
}

signed main() {
   
    for(int i=1;i<=300;i++){
        if(!isQ(i) && check(i)){
            cout<<i<<" ";
            cnt++;
        } 
        // cout<<cnt<<" ";    
    }
    cout<<endl;
    
    return 0;
}
