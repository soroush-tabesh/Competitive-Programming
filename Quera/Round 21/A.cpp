//In The Name of Allah
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

ll n2p[200*1000+5];
ll p2n[200*1000+5];
ll n;
vector<pll> sol;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void subs(ll pa,ll pb){
	swap(p2n[pa],p2n[pb]);
	swap(n2p[p2n[pa]],n2p[p2n[pb]]);
}

void Solution(){
	cin >> n;
	ll limit = (n/2)+1;
	fori(i,1,n+1){
		ll a;
		cin >> a;
		n2p[a] = i;
		p2n[i] = a;
	}
	fori(i,1,n+1){
		if(n2p[i] == i)
			continue;
		if(abs(n2p[i]-i) <= limit){
			sol.pb({n2p[i],i});
			subs(n2p[i],i);
		}else{
			ll t = n2p[i];
			sol.pb({n2p[i],(i+t)/2});
			subs(n2p[i],(i+t)/2);
			sol.pb({i,(i+t)/2});
			subs(i,(i+t)/2);
		}
	}
	cout << sol.size() << endl;
	for(pll x : sol){
		cout << x.F << " " << x.S << endl;
	}
}