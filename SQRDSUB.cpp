#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll max1 =(ll)1e9;
int main(){
  ll i,j,k,n,m,ct=0,t,ans=0;
  cin>>t;
  while(t--){
  	cin>>n;
  	ans=0;
  	ll a[n];
  	vector<ll> b;
     for(i=0;i<n;i++){
  		cin>>k;
  		a[i]=k%4;
  		if(a[i]==0||a[i]==2) b.push_back(i);
	  }
	 i=0;j=0;
	 while(j<b.size()){
	 	m=b[j]-i;
	 	ans+=(m*(m+1)/2);
	 	if(a[b[j]]==0 && j!=(b.size()-1)){
	 		ans+=((m+1)*(n-b[j]));
	 		i=b[j]+1;
		 }
	else if(a[b[j]]==0 && j==(b.size()-1)){
	//	ans+=(((n-b[j])*(n-b[j]+1))/2);
			k=i;
			ans+=(((n-i)*(n-i+1))/2-((m)*(m+1))/2);
		
		}
		else{
			if(j!=(b.size()-1)){
				ans+=((m+1)*(n-b[j+1]));
				i=b[j]+1;
			}
			else{
				ans+=(((n-b[j]-1)*(n-b[j]))/2);
			}
		}
		j++;
	 }
	 if(b.size()==0) cout<<((n*(n+1))/2)<<"\n";
	 else cout<<ans<<"\n";
  }
  return 0;
}
