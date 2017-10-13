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

const ll delta = 11743;

void SolutionA();
void SolutionB();
void SolutionC();
void SolutionD();

int main()
{
	Init;
	//WFile;
	//SolutionA();
	//SolutionB();
	SolutionC();
	//SolutionD();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	ll v = ppow(base,exp/2);
	v*=v;
	if(exp%2)
		v*=base;
	return v%delta;
}

void SolutionA(){
	ll p=1,pp=1,m=13,n=11;
	bool is = true;
	ll i = 2;
	while(is){
		i++;
		i%=delta;
		ll t = (pp + p)%m;
		pp = p;
		p = t;
		if(p == n)
			is = false;
	}
	ll ans = ppow(i,10);
	cout << ans;
}

void SolutionB(){
	ll p=1,pp=1,m=1e8,n=90234383;
	bool is = true;
	ll i = 2;
	while(is){
		i++;
		i%=delta;
		ll t = (pp + p)%m;
		pp = p;
		p = t;
		if(p == n)
			is = false;
	}
	cout << i;
}

ll funcf(ll m){
	ll p=1,pp=1,n=0;
	bool is = true;
	ll i = 2;
	while(is){
		i++;
		i%=delta;
		ll t = (pp + p)%m;
		pp = p;
		p = t;
		if(p == n)
			is = false;
	}
	return i;
}

bool isprime(ll x){
	for(int i = 2; i*i <= x;i++){
		if(x%i == 0)
			return false;
	}
	return true;
}

void SolutionC(){
	ll i = 3;
	ll n = (1e9) * 2;
	ll ans = 0;
	while(i*i-5 <= n){
		if(isprime(i*i-5)){
			ll t = funcf(i*i-5);
			//cout << (i*i-5) << " " << t << endl;
			ans += t;
			ans %= delta;
		}
		i++;
	}
	cout << delta << endl;
}

void SolutionD(){
	ll p=1,pp=1,m=1e8,n=1378137813787LL;
	m*=1e5;
	bool is = true;
	ll i = 2;
	while(is){
		i++;
		i%=delta;
		ll t = (pp + p)%m;
		pp = p;
		p = t;
		if(p == n)
			is = false;
	}
	cout << i << endl;
	cin >> i;
	cin >> i;
}
