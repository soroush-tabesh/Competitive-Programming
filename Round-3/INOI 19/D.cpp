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

const ll delta = 10337;

void Solution();

pll rate[6];
vector<ll> primes;
ll dp[10*1000*1000];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

bool isprime(ll x){
	int i = 0;
	while(i < primes.size() && primes[i]*primes[i] <= x){
		if(x%primes[i] == 0)
			return false;
		i++;
	}
	return true;
}

bool isinprimes(ll x){
	return (*(lower_bound(primes.begin(),primes.end(),x)) == x);
}

void mkprime(ll t){
	primes.pb(2);
	fori(i,3,t+1){
		if(isprime(i)){
			primes.pb(i);
		}
	}
}

ll denomcount(ll x){
	ll cnt = 1;
	for(ll p : primes){
		if(p > x)
			break;
		ll k = 1;
		while(x%p == 0){
			k++;
			x/=p;
		}
		cnt *= k;
	}
	return cnt;
}

ll factorcount(ll x,ll factor){
	ll cnt = 0;
	while(x%factor == 0){
		cnt++;
		x/=factor;
	}
	return cnt;
}

void Solution(){
	mkprime(10*1000*1000);
	fori(i,1,100){
		dp[i] = denomcount(i);
	}
	fori(i,100,10*1000*1000+1){
		if(isinprimes(i))
			continue;
		ll t = 0;
		for(ll p : primes){
			if(i%p == 0){
				t = dp[i/p];
				ll f = factorcount(i/p,p);
				t /= f+1;
				t *= f+2;
				dp[i] = t;
				break;
			}
		}
		rate[5] = (make_pair(t,i));
		sort(rate,rate + 6,greater<pll>());
	}
	cout << rate[3].S % delta << endl;
}
