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

const ll delta = 10259;

void SolutionA();

int main()
{
	Init;
	//WFile;
	SolutionA();
	return 0;
}

ll ppow(ll base,ll exp,bool usedelta = true){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	ll v = ppow(base,exp/2);
	v*=v;
	if(exp % 2 == 1)
		v*=base;
	if(usedelta)
		v%=delta;
	return v;
}

ll convert(ll x){
	ll t = x;
	while(t > 0){
		t-= t&(-t);
		x<<=1;
		x%=delta;
	}
	return x;
}

void SolutionA(){
	ll n = 10;
	ll ans = 0;
	forar(i,ppow(2,n,false)){
		ans += convert(i);
		ans %= delta;
	}
	Log(ans);
	cout << ppow(ans,3) << endl;
}

