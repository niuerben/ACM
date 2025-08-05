#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 2e5+9;
int a[N],e[N];
int main(){
	for(int i=1;i<=n;i++) cin>>a[i];
	
    

	int len=0;
	for(int i=1;i<=n;i++){
		if(e[len]<=a[i]) e[++len]=a[i];
		else{
			int pos=upper_bound(e,e+len+1,a[i])-e;
			e[pos]=a[i];
		}
		
	}
	
	printf("%d\n%d",len);
	return 0;
}
/*1 2 5 6 8 9 3 1*/