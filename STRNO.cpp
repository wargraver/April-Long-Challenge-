#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	ll i,j,k,n,m,ct=0,t,l;
	cin>>t;
	while(t--){
		cin>>n>>k;
		i=0;ct=0;
		map<ll,ll> dict;
	     while (n % 2 == 0){  
        ct++;
        n = n/2;}  
    for (int i = 3; i <= sqrt(n); i = i + 2){  
        while (n % i == 0)  
        {  
            ct++;  
            n = n/i;  
        }  
    }  
    if (n > 2)  ct+=1;  
		if(ct>=k) cout<<"1"<<endl;
		else cout<<"0"<<endl;
	}
	return 0;
}
