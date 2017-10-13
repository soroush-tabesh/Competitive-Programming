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
	SolutionB();
	//SolutionC();
	//1SolutionD();
	return 0;
}

ld harmonic(ll i){
	ld res = 0;
	while(i>0){
		ld t = i;
		ld t2 = 1;
		t = t2 / t;
		res += t;
		i--;
	}
	return res;
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
	ld n,k;
	n = 4;
	k = 1;
	n *= harmonic(n);
	n *= k;
	
	n*=1000;
	n=floor(n);
	ll ans = llround(n);
	ans = ppow(ans,5);
	cout << ans << endl;
}

void SolutionB(){
	ld n,k;
	n = 15;
	k = 2;
	n *= harmonic(n);
	n *= k;
	
	n *= 1000;
	n = floor(n);
	ll ans = llround(n);
	ans = ppow(ans,5);
	cout << ans << endl;
}

void SolutionC(){
	ld n,k;
	n = 13781378;
	k = 1;
	n *= harmonic(n);
	n *= k;
	
	n *= 1000;
	n = floor(n);
	ll ans = llround(n);
	cout << ans%delta << endl;
}

void SolutionD(){
	ld n = 1e9;
	n*=n;
	n*=2;
	n = log(n);
	n+=0.7;
	n*=2;
	
	n = floor(n);
	ll ans = llround(n);
	ans = ppow(ans,5);
	cout << ans << endl;
}

