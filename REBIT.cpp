#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long lll;
ll max1 =998244353;
ll gcdExtended(ll a, ll b, ll *x, ll *y); 
ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    { 
        // m is added to handle negative x 
        ll res = (x%m + m) % m; 
        return res; 
    } 
} 
  
// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
ll value(ll x,ll y,char op){
	if(op=='&'){
		if(x==0 || y==0 || (x==3 && y==2 ) || (y==3 && x==2)) return 0;
		else if(x==1 && y==1) return 1;
		else if((x==2&&y==1)||(x==1&&y==2)||(x==2&&y==2)) return 2;
		else return 3;
	}
	else if(op=='|'){
		if(x==0 && y==0) return 0;
		else if((x==2&&y==0)||(x==0&&y==2)||(x==2&&y==2)) return 2;
		else if((x==3&&y==0)||(x==0&&y==3)||(x==3&&y==3)) return 3;
		else return 1;
	}
	else{
		if(x==y) return 0;
		else if((x==1&&y==0)||(x==0&&y==1)||(x==2&&y==3)||(x==3&&y==2)) return 1;
        else if((x==2&&y==0)||(x==0&&y==2)||(x==3&&y==1)||(x==1&&y==3))	return 2;
        else return 3;
	}
}
vector<ll> ways(vector<char> postfix){
	ll n,m,j,k,i;
	ll count=0;
	stack<vector<ll>> a;
	for(k=0;k<postfix.size();k++){
		if(postfix[k]!='#'){
			vector<ll> z=a.top();
			a.pop();
			vector<ll> y=a.top();
			a.pop();
			vector<ll> x(4,0);
			for(i=0;i<=3;i++){
				for(j=0;j<=3;j++){
					ll zo=value(i,j,postfix[k]);
					if(zo==0){
					x[0]+=((y[i]%max1)*(z[j]%max1))%max1;
					x[0]=x[0]%max1;	
					}
					else if(zo==1){
					x[1]+=((y[i]%max1)*(z[j]%max1))%max1;	
					x[1]=x[1]%max1;
					}
					else if(zo==2){
						x[2]+=((y[i]%max1)*(z[j]%max1))%max1;
						x[2]=x[2]%max1;
					}
					else{
						x[3]+=((y[i]%max1)*(z[j]%max1))%max1;
						x[3]=x[3]%max1;
					}
				}
			}
			a.push(x);
		}
		else{
			vector<ll> x(4,1);
			a.push(x);
		}
	}
	return a.top();
}
int main(){
  ll i,j,k,n,m,ct=0,t,ans=0;
  cin>>t;
  while(t--){
  	 string str;
	 vector<char> postfix;
  	 cin>>str;ct=0;
  	 ll l=str.length();
  	 stack<char> st;
  	 i=0;j=0;ct=0;
  	 while(i<l){
  	 	     if(str[i]!=')'){
  	 	  	    if(str[i]=='#'){
  	 	  	 	  postfix.push_back('#');
  	 	  	 	  ct++;
				 }
			  else st.push(str[i]);
			 }
			else{
				while(st.top()!='('){
					postfix.push_back(st.top());
					st.pop();
				}
				st.pop();
			}
			i++;
	   }
	while(!st.empty()){
		if(st.top()!='(') postfix.push_back(st.top());
		st.pop();
	}
	//for(i=0;i<postfix.size();i++) cout<<postfix[i];
	//cout<<endl;
	vector<ll> z=ways(postfix);
//for(int x:z) cout<<x<<" ";
//	cout<<endl;
	 ll total=1;
	 for(i=1;i<=ct;i++) total=((total%max1)*4)%max1;
	 total=total%998244353;
	 total=modInverse(total,max1);
	 total=total%998244353;
	 for(ll x:z){
	 	ll y=x%max1;
	 	lll x1=(y*total)%max1;
	 	cout<<x1<<" ";
	 }
	 cout<<endl;
  }
  return 0;
}
