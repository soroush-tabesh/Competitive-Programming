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

const ll delta = 10667;

void SolutionA();
void SolutionB();
void SolutionC();

ll dpcomb[2000][2000];

int main()
{
	Init;
	//WFile;
	//SolutionA();
	//SolutionB();
	SolutionC();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	ll v = ppow(base,exp/2);
	v*=v;
	if(exp%2==1)
		v*=base;
	return v%delta;
}

ll combine(ll n, ll r){
	if( n < 0 || r < 0)
		return 0;
	if(dpcomb[n][r] != 0)
		return dpcomb[n][r];
	if(r > n)
		return 0;
	if(r == n || r == 0)
		return 1;
	dpcomb[n][r] = combine(n-1,r) + combine(n-1,r-1);
	dpcomb[n][r] %= delta;
	return dpcomb[n][r];
}

void SolutionA(){
	ll n = 1000;
	ll ans = 0;
	fori(aorb,1,n){
		if(aorb % 10 == 0)
			Log(aorb);
		fori(aandb,1,aorb+1){
			fori(a,0,aorb-aandb+1){
				ll temp = combine(n,aorb);
				temp *= combine(aorb,aandb);
				temp *= combine(aorb-aandb,a);
				temp *= ((ppow(2,n-aorb)-1)+delta)%delta;
				temp %= delta;
				ans += temp;
				ans %= delta;
			}
		}
	}
	cout << ans << endl;
}

void SolutionB(){
	ll n = 1000;
	ll ans = 0;
	fori(c,200,800+1){
		if(c % 10 == 0)
			Log(c);
		fori(aorb,200,c+1){
			fori(aandb,200,aorb+1){
				fori(a,0,aorb-aandb+1){
					ll temp = combine(n,c);
					temp *= combine(c,aorb);
					temp %= delta;
					temp *= combine(aorb,aandb);
					temp *= combine(aorb-aandb,a);
					
					temp %= delta;
					ans += temp;
					ans %= delta;
				}
			}
		}
	}
	cout << ans << endl;
}

void SolutionC(){
	ll n = 1000;
	ll ans = 0;
	fori(c,300,n+1){
		if(c % 10 == 0)
			Log(c);
		fori(aorb,300,c+1){
			fori(aandb,0,aorb-300+1){
				fori(a,0,min(c-320,aorb-aandb)+1){
					if(aorb - a > c-320)
						continue;
					ll temp = combine(n,c);
					temp *= combine(c,aorb);
					temp %= delta;
					temp *= combine(aorb,aandb);
					temp *= combine(aorb-aandb,a);
					
					temp %= delta;
					ans += temp;
					ans %= delta;
				}
			}
		}
	}
	cout << ans << endl;
}
