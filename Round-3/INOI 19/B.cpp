//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll delta = 10337;

void Solution();

vector<ll> fibo;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

bool isprime(int x){
	for(int y : fibo){
		if(x % y == 0)
			return false;
	}
	return true;
}

void Solution(){
	ll pp = 1;
	ll p = 2;
	while(p < 1000*1000){
		fibo.pb(p);
		ll t = pp + p;
		pp = p;
		p = t;
	}
	ld cnt = 0;
	fori(x,100*1000,1000*1000){
		if(x%2 == 0)
			continue;
		if(isprime(x)){
			cnt++;
		}
	}
	cnt /= double(900*1000);
	cnt *= double(100);
	cnt *= double(delta);
	cout.precision(5);
	cout << fixed;
	cout << cnt << endl;
}