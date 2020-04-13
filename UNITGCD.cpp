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
  ll i,j,k,n,m,ct=0,t,ans=0;
  cin>>t;
  while(t--){
  	cin>>n;
  	if(n==1) printf("1\n1 1\n");
  	else{
  		printf("%ld\n",n/2);
  		if(n%2==0){
  			j=0;
  			for(i=1;i<=n/2;i++){
  				j++;
  				printf("2 ");
				printf("%ld %ld\n",j,j+1);
  				j++;
			  }
		  }
		 else{
		 	j=4;
		 	printf("3 1 2 3\n");
		 	for(i=2;i<=n/2;i++){
		 		printf("2 ");
		 		printf("%lld %lld\n",j,j+1);
		 		j+=2;
			 }
		 } 
	  }
}
  return 0;
}
