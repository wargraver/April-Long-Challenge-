#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void swap(ll *x,ll *y){
	ll j=*y;
	*y=*x;
	*x=j;
}
ll max1 = 1000000007;
int main(){
  ll i,j,k,n,m,ct=0,t,ans=0;
  cin>>t;
  while(t--){
  	cin>>n;
  	ct=0;
  	vector<ll> vec;
  	for(i=0;i<n;i++){
  		cin>>k;
  		vec.push_back(k);
	  }
	  sort(vec.begin(),vec.end());
	  j=n-1;
	for(i=0;i<n;i++){
		m=vec[i]-j;
		if(m>=0){
			m=m%max1;
			ct=ct%max1;
			ct+=m;
			ct=ct%max1;
		}
		j--;
	}
	cout<<ct<<endl;
  }
  return 0;
}
