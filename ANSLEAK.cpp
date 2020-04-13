#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void swap(ll *x,ll *y){
	ll j=*y;
	*y=*x;
	*x=j;
}
ll max1 =(ll)1e9;
int main(){
  ll i,j,key,n,m,ct=0,t,ans=0,x1,x2,x3,y1,y2,y3;
  cin>>t;//testcases
  while(t--){
  	cin>>n>>m>>key;
  	int a[n][key];
  	for(i=0;i<n;i++){
  		for(j=0;j<key;j++) cin>>a[i][j];
	  }
  i=0;
  j=1;
  cout<<a[i][j]<<" ";
  for(i=1;i<n;i++){
     j=(n-i-1)%key;
     cout<<a[i][j]<<" ";
  }
  cout<<" "<<endl;
}
  return 0;
}
