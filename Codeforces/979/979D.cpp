//In The Name of Allah
//Mon 24/2/97
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

ll q;
set<ll> muls[M];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> q;
	while(q--){
		ll m_t;
		cin >> m_t;
		if(m_t == 1){
			ll u;
			cin >> u;
			for(ll j = 1;j*j <= u;j++){
				if(u%j)
					continue;
				muls[j].insert(u);
				muls[u/j].insert(u);
			}
		}else{
			ll x,k,s;
			cin >> x >> k >> s;
			if(x%k || muls[k].empty() || (*muls[k].begin())>s-x){
				cout << -1 << endl;
				continue;
			}
			s-=x;
			ll pref = 0;
			for(int i = 16;i >= 0;i--){
				ll des = (x&(1<<i))^(1<<i);
				pref ^= des;
				auto it = muls[k].lower_bound(pref);
				if(it == muls[k].end() || *it > s || *it >= (pref^des)+(1<<(i+1))){
					it = muls[k].lower_bound(pref^des);
				}
				pref ^= des;
				pref ^= (*it) & (1<<i);
			}
			cout << pref << endl;
		}
	}
}
