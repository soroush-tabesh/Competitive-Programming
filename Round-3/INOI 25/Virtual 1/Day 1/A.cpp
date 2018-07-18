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

const ll delta = 10513;

void SolutionA();

ll dpcolnumsel[1000*1000+5]; // index=count value=count of grids
ll dpcomb[1000][1000];
ll n;

int main()
{
	Init;
	WFile;
	SolutionA();
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

void SolutionA(){
	n = 5;
	ll ans = 0;
}

