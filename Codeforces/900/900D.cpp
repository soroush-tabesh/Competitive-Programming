//In The Name of Allah
//Mon 20/9/96
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

ll nsum,ngcd,ans;
bool sieve[M];
vector<ll> primes;
map<int,int> comps;
vector<pii> proc;

int main()
{
	Init;
	Solution();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	ll v = ppow(base,exp/2);
	v*=v;
	v%=mod;
	if(exp%2)
		v*=base;
	return v%mod;
}

ll dec(ll n){
	for(int k : primes){
		if(k*k > n)
			break;
		while(n%k == 0)
			n/=k,comps[k]++;
	}
	if(n>1){
		comps[n]++;
	}
	for(pii k : comps){
		proc.pb(k);
	}
}

void solve(ll pos,ll cur,ll cnt){
	if(pos >= proc.size()){
		ans -= (((cnt%2)*2)-1)*ppow(2,(nsum/cur)-1);
		ans += 2*mod;
		ans %= mod;
		return;
	}
	solve(pos+1,cur,cnt);
	solve(pos+1,cur*proc[pos].F,cnt+1);
}

void Solution(){
	cin >> ngcd >> nsum;
	fori(i,2,200*1000){
		if(!sieve[i]){
			primes.pb(i);
			for(ll j = 2*i;j < M;j+=i){
				sieve[j] = 1;
			}
		}
	}
	if(nsum%ngcd){
		cout << 0 << endl;
		return;
	}
	nsum /= ngcd;
	if(nsum == 1){
		cout << 1 << endl;
		return;
	}
	dec(nsum);
	solve(0,1,0);
	cout << ans << endl;
}
