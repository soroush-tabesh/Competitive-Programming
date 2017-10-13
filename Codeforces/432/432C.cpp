//In The Name of Allah
//Date : 21/5/96
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
ll pos2num[100*1000+5];
ll num2pos[100*1000+5];
vector<ll> primes;
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
	swap(pos2num[pa],pos2num[pb]);
	swap(num2pos[pos2num[pa]],num2pos[pos2num[pb]]);
}

bool isprime(ll x){
	for(ll k : primes){
		if(k*k > x)
			return true;
		if(x%k == 0)
			return false;
	}
	return true;
}

void genprimes(){
	fori(i,2,100*1000){
		if(isprime(i)){
			primes.pb(i);
		}
	}
}

ll findprime(ll x){
	vector<ll>::iterator it = lower_bound(primes.begin(),primes.end(),x);
	if(*it == x)
		return x;
	it--;
	return *it;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> pos2num[i];
		pos2num[i]--;
		num2pos[pos2num[i]] = i;
	}
	genprimes();
	forar(i,n){
		while(num2pos[i] != i){
			ll dist = abs(num2pos[i] - i);
			ll mv = findprime(dist+1)-1;
			if(i < num2pos[i]){
				sol.pb({num2pos[i] - mv,num2pos[i]});
				subs(num2pos[i],num2pos[i] - mv);
			}else{
				sol.pb({num2pos[i],num2pos[i] + mv});
				subs(num2pos[i],num2pos[i] + mv);
			}
		}
	}
	cout << sol.size() << endl;
	for(pll k : sol){
		cout << k.F+1 << " " << k.S+1 << endl;
	}
	
}