#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10, inf = 1e9, mod = 1e9+7;

signed main() {
    int t;cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        int ans = 0;
        vector<int> ansV;
        // 1. a ← a · 2；
        // 2. b ← ⌊ b/2 ⌋；
        // 3. a ← a ⊕ b，其中 ⊕ 指按位异或；
        // 4. b ← b ⊕ a。
        if(!a && !b && c) {
            cout<<-1<<'\n';
            continue;
        }
        

        int lenA = floor(log2(a))+1;
        int lenB = floor(log2(b))+1;
        int lenC = floor(log2(c))+1;
        if(!a) lenA = 0;
        if(!b) lenB = 0;
        if(!c) lenC = 0;
            
        // 进行最多一次异或操作，让a和b的最高位相同
        if(lenA<lenB){
            a ^= b;
            lenA = lenB;
            ans++;
            ansV.push_back(3);
        }
        else if(lenA > lenB){
            b ^= a;
            lenB = lenA;
            ans++;
            ansV.push_back(4);
        }

        // c为最大值时
        int curCBit = lenC-1;
        // 改掉一个参数就ac了
        int tmp = lenA-1;
        if(lenC>=max(lenA,lenB)){
            // 让a不断乘2，在这个过程中用a←a⊕b进行调整
            while(lenA<lenC){
                // 第curCBit位保持一直
                if(((a^b)>>(tmp)) == (c>>curCBit)){
                    a = a^b;
                    ans++;
                    ansV.push_back(3);
                }
                // a*2
                a<<=1;
                curCBit--;
                lenA++;
                ans++;
                ansV.push_back(1);
            }
        }
        // 让b不断除2，在这个过程中用b←a⊕b进行调整
        curCBit = lenB-1;
        while(lenB){
            // 第curCBit位保持一直
            if(((a^b)>>curCBit) == (c>>curCBit)){
                a = a^b;
                ans++;
                ansV.push_back(3);
            }
            b>>=1;
            curCBit--;
            lenB--;
            ans++;
            ansV.push_back(2);
        }

        b^=a;
        ans++;
        ansV.push_back(4);
    
    
        cout<<ans<<'\n';
        for(auto i:ansV) cout<<i<<" ";cout<<'\n';
        
    }
    return 0;
}
    