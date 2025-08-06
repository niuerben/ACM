#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 210, inf = 1e9, mod = 1e9+7;
int n,a,b;

int dp[N][N][N];

int zeros,ones;
vector<string> strings;
void zerosAndOnes(string s){
    for(int i=0;i<s.size();i++) 
        if(s[i]=='0') zeros++;
        else ones++;
}
int f(int i,int z,int o){
    if(i==n) return 0;
    if(dp[i][z][o]) return dp[i][z][o];

    int p1 = f(i+1,z,o);
    int p2 = 0;
    zeros = ones = 0;
    zerosAndOnes(strings[i]);
    if(z>=zeros && o>=ones) p2 = 1+f(i+1,z-zeros,o-ones);
    return dp[i][z][o] = max(p1,p2);
}


signed main() {
    cin>>n>>a>>b;
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        strings.push_back(s);
    }

    cout<<f(0,a,b)<<endl;
    // for(int k=0;k<=b;k++){
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<=a;j++){
    //             cout<<dp[i][j][k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    return 0;
}

/*
for(int i=1;i<=n;i++){
    for(int j=a;j>=0;j--){
        for(int k=b;k>=0;k--){
            dp[i][j][k] = dp[i-1][j][k];
            if(j-zero[i]>=0 && k-ones[i]>=0)
                dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-zeros[i]][k-ones[i]]);
        }
    }   
}
*/