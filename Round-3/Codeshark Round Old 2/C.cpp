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

const ll delta = 12841;

void SolutionA();
void SolutionB();

ll dpcomb[1000][1000];

int main()
{
	Init;
	//WFile;
	SolutionA();
	SolutionB();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	ll v = ppow(base,exp/2);
	v*=v;
	v%=delta;
	if(exp % 2 == 1)
		v *= base;
	v%=delta;
	return v;
}

ll comb(ll n,ll r){
	if(n < 0 || r < 0 || r > n)
		return 0;
	if( n == r || r == 0)
		return 1;
	if(dpcomb[n][r] != 0)
		return dpcomb[n][r];
	dpcomb[n][r] = comb(n-1,r) + comb(n-1,r-1);
	dpcomb[n][r] %= delta;
	return dpcomb[n][r];
}

void SolutionA(){
	ll ans = 0;
	fori(i,2,11){
		fori(j,2,11){
			ans += comb((i+1)*(j+1),2);
			ans %= delta;
		}
	}
	cout << ans;
}

void SolutionB(){
	ll n=10,w=55,h=75,d=5;
	
}
