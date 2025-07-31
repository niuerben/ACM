#include <bits/stdc++.h>
using namespace std;

void change(vector<int> &a){
    if(a.size() == 1) {
        cout<<a[0]<<" ";
        return;
    }
    
    vector<int> b;
    vector<int> c;
    for(int i=0;i<a.size();i++){
        if(i&1) c.push_back(a[i]);
        else b.push_back(a[i]);
    }
    change(b);
    change(c);
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    change(a);
}