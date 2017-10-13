//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll delta = 12527;

void SolutionA();


int main()
{
	Init;
	//WFile;
	SolutionA();
	return 0;
}

ll findperiod(ll n,ll mod){
	ll x = n;
	ll cnt = 1;
	ll mmd = x%mod;
	bool is = true;
	while(is){
		x*=n;
		x%=mod;
		if(x == mmd)
			is = false;
		else
			cnt++;
	}
	return cnt;
}

void SolutionA(){
	ll ans = 0;
	ll n = 1234;
	fori(i,1,n){
		Log(i);
		ans += findperiod(i,n);
		ans %= delta;
	}
	cout << ans << endl;
}
