//In The Name of Allah
//Sun 23/2/97
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

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	int pw = 1000,mx = 350;
	vector<int> digs(mx);
	digs[0] = 1;
	forar(iter,pw){
		ll carry = 0;
		forar(k,mx){
			carry += (digs[k]*2);
			digs[k] = carry%10;
			carry /= 10;
		}
	}
	ll ans = 0;
	forar(i,mx){
		ans += digs[i];
	}
	cout << ans << endl;
}
