//In The Name of Allah
//Mon 30/5/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
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

const ll mod = 1e9+7;

void Solution();

ll n;
pll data[100*1000+5];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

bool compA(pll a ,pll b){
	return ((a.F + a.S)<(b.F + b.S));
}

bool compB(pll a ,pll b){
	return ((a.F - a.S)<(b.F - b.S));
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i].F >> data[i].S;
	}
	ll ans = 0;
	pll a = data[0];
	pll b = data[0];
	pll c = data[0];
	pll d = data[0];
	forar(i,n){
		if(compA(a,data[i]))
			a = data[i];
		if(!compA(b,data[i]))
			b = data[i];
		if(compB(c,data[i]))
			c = data[i];
		if(!compB(d,data[i]))
			d = data[i];
	}
	ans = max(ans,abs(a.F-b.F) + abs(a.S-b.S));
	ans = max(ans,abs(c.F-d.F) + abs(c.S-d.S));
	cout << ans << endl;
}

 