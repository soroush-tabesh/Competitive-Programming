//In The Name of Allah
//Thu 30/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e2+5;

void Solution();

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	ll x;
	cin >> x;
	while(x%10==0) x/=10;
	ll t = x;
	ll n = 0;
	while(t>0){
		n*=10;
		n+=t%10;
		t/=10;
	}
	if(n==x){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
