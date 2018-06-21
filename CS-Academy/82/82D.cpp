//In The Name of Allah
//Tue 30/3/97
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fori(i,a,b) for(ll i = a; i < b;i++)
#define forar(i,n) fori(i,0,n)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LSB(x) (x&(-x))

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

ll n,k,ans = 1,mul;
ll dt[M];
map<ll,ll> exs;

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n >> k;
	forar(i,n){
		cin >> dt[i];
		if(i>=k){
			exs[dt[i-k]]--;
			if(exs[dt[i-k]] == 0){
				exs.erase(dt[i-k]);
			}
		}
		exs[dt[i]]++;
		mul = max(mul,(ll)exs.size());
	}
	exs.clear();
	forar(i,n){
		if(i>=k){
			exs[dt[i-k]]--;
			if(exs[dt[i-k]] == 0){
				exs.erase(dt[i-k]);
			}
		}
		exs[dt[i]]++;
		if(exs[dt[i]] == 1){
			ans *= mul-exs.size()+1;
			ans %= mod;
		}
	}
	cout << ans << endl;
}
