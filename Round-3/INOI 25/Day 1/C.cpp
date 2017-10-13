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

const ll delta = 1000*1000*1000 + 7;

void Solution();

int sel[8];
ll dpcomb[10000][10000];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}


ll ppow(ll base ,ll exp,bool usedelta = true){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	ll v = ppow(base,exp/2);
	v*=v;
	if(usedelta)
		v%=delta;
	if(exp % 2 == 1)
		v*=base;
	if(usedelta)
		v%=delta;
	return v;
}

ll comb(ll n ,ll r){
	if(n < r || r < 0)
		return 0;
	if(n == r || r == 0)
		return 1;
	if(dpcomb[n][r] != 0)
		return dpcomb[n][r];
	int res = comb(n-1,r) + comb(n-1,r-1);
	res %= delta;
	dpcomb[n][r] = res;
	return res;
}

ll fact(ll n){
	ll res = 1;
	while(n > 0){
		res *= n;
		res %= delta;
		n--;
	}
	return res;
}

void Solution(){
	ll n=22,t=44,k=88;
	ll v = ppow(2,n);
	for(int i = 1;i <= k;i++){
		v *= ppow(2,n)-i;
		v %= delta;
	}
	v *= comb(k+1,t);
	v %= delta;
	ll den = fact(k+1);;
	while(v%den != 0){
		v+=delta;
	}
	ll ans = (v/den)%delta;
	ans %= 10513;
	cout << ans << endl;
}

