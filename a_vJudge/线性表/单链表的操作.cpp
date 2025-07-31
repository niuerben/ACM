#include<bits/stdc++.h>
using namespace std;
int n,m;
int flag,ix,iy;
signed main() {
    cin>>n>>m;
    list<int> ls1;
    list<int> ls2;
    for(int i=1;i<=n;i++) {
        ls1.push_back((int)10000*sin(n+i));
        ls2.push_back((int)10000*sin(m+i));
    }

    for(int i=1;i<=m;i++){
        cin>>flag>>ix>>iy;
        ix--;iy--;
        auto it1 = ls1.begin();
        auto it2 = ls2.begin();

        if(!flag){
            advance(it1,ix);
            advance(it2,iy);
            ls2.insert(it2,*it1);
            ls1.erase(it1);
        }

        else{
            advance(it2,ix);
            advance(it1,iy);
            ls1.insert(it1,*it2);
            ls2.erase(it2);
        }
    }

    
    int start,end;
    cin>>start>>end;
    start--;end--;
    auto it = ls1.begin();
    advance(it,start);
    for(int i=start;i<end;i++){
        cout<<*it<<'\n';
        advance(it,1);
    }
    return 0;
}


/*
signed main() {
    cin>>n>>m;
    deque<int> dq1, dq2;

    for(int i=1;i<=n;i++)
        dq1.push_back((int)(10000*sin(n+i)));

    for(int i=1;i<=n;i++)
        dq2.push_back((int)(10000*sin(m+i)));

    for(int i=1;i<=m;i++){
        cin>>flag>>ix>>iy;
        ix--; iy--;

        if(!flag){
            int val = dq1[ix];
            dq2.insert(dq2.begin() + iy, val);
            dq1.erase(dq1.begin() + ix);
        }
        else{
            int val = dq2[ix];
            dq1.insert(dq1.begin() + iy, val);
            dq2.erase(dq2.begin() + ix);
        }
    }

    int start,end;
    cin>>start>>end;
    start--; end--;

    for(int i=start;i<end;i++)
        cout<<dq1[i]<<'\n';

    return 0;
}
*/