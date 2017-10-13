/*
ID: soroosh4
LANG: C++11
TASK: sprime
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("sprime.in","r",stdin),freopen("sprime.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
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
const int M = 100*1000+5;

void Solution();

vector<int> primes = {2,3};
vector<int> ans[9];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

int ppow(int n,int exp){
	if(exp==1)
		return n;
	if(exp==0)
		return 1;
	int k = ppow(n,exp/2);
	k *= k;
	k *= (exp%2 == 1) ? n : 1;
	return k;
}

bool isprime(int n){
	if(n > primes.back()){
		int i = 0;
		while(i < primes.size() && primes[i]*primes[i] <= n){
			if(n%primes[i] == 0)
				return false;
			i++;
		}
		return true;		
	}else{
		int query = *lower_bound(primes.begin(),primes.end(),n);
		return n == query;
	}
}

void genPrimes(int limit){
	fori(i,4,limit+1){
		if(isprime(i)){
			primes.pb(i);
		}
	}
}

void solve(int n){
	if(n > 1)
		solve(n-1);
	for(int k : ans[n-1]){
		forar(i,5){
			int toadd = k*10 + 2*i+1;
			if(isprime(toadd))
				ans[n].pb(toadd);
		}
	}
}

void Solution(){
	int n;
	cin >> n;
	genPrimes(10000);
	ans[0].pb(0);
	ans[1].pb(2);
	solve(n);
	for(int k : ans[n])
		cout << k << endl;
}
