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

ll delta = 680027;

void SolutionA();
void SolutionB();
void SolutionC();

int main()
{
	Init;
	//WFile;
	//SolutionA();
	//SolutionB();
	SolutionC();
	return 0;
}

ll ppow(ll base,ll exp,bool usedelta = true){
	if(exp == 0)
		return 1;
	ll v = ppow(base,exp/2);
	v*=v;
	if(usedelta)
		v%=delta;
	if(exp % 2 == 1)
		v *= base;
	if(usedelta)
		v%=delta;
	return v;
}

void SolutionA(){
	ll ans = 0;
	ll n = ppow(10,6);
	ll lgm = llround(floor(log2(10)*double(6)));
	ll ip2 = 0;
	while(ip2 < lgm){
		ll p2 = ppow(2,ip2);
		n -= p2;
		n += delta;
		n %= delta;
		ans += ppow(p2,2);
		ans %= delta;
		ip2++;
	}
	ans += ppow(n,2);
	ans %= delta;
	cout << ans << endl;
}

void SolutionB(){
	ll ans = 0;
	ll n = ppow(10,17);
	ll lgm = llround(floor(log2(10)*double(17)));
	ll ip2 = 0;
	while(ip2 < lgm){
		ll p2 = ppow(2,ip2);
		n -= p2;
		n += delta;
		n %= delta;
		ans += ppow(p2,2);
		ans %= delta;
		ip2++;
	}
	ans += ppow(n,2);
	ans %= delta;
	cout << ans << endl;
}

ll findperiod(ll n){
	map<ll,bool> rems;
	ll x = 1;
	bool is = true;
	while(is){
		x*=n;
		x%=delta;
		if(!rems[x])
			rems[x] = 1;
		else
			is = false;
	}
	return rems.size();
}

ll solveC(){
	ll ans = 0;
	ll n = ppow(10,100);
	ll lgm = llround(floor(log2(10)*double(100)));
	ll ip2 = 0;
	while(ip2 < lgm){
		ll p2 = ppow(2,ip2);
		n -= p2;
		n += delta;
		n %= delta;
		ans += ppow(p2,2);
		ans %= delta;
		ip2++;
	}
	ans += ppow(n,2);
	ans %= delta;
	return ans;
}

void SolutionC(){
	delta *= 3;
	ll ans1 = solveC();
	
	ll dlp = delta;
	ll per = findperiod(ans1);
	delta = per;
	
	ll ans2 = solveC();
	
	delta = dlp;
	
	ll ans = ppow(ans1,ans2+per);
	cout << ans << endl;
}
