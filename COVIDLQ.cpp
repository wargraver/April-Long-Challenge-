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
  ll i,j,k,n,m,ct=0,t,ans=0,flag;
  cin>>t;
  while(t--){
  	cin>>n;
  	flag=0;
  	vector<ll> a;
  	for(i=0;i<n;i++){
  		cin>>k;
  		if(k==1) a.push_back(i);
	  }
	for(i=0;i<a.size()-1;i++){
		if(a[i+1]-a[i]<6) flag=1;
	}
	if(flag==1) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;  
  }
  return 0;
}
