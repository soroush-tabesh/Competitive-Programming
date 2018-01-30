//In The Name of Allah
//Sat 30/10/96
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

string n;
int k;
ll fac[2000],rfac[2000];
int dp[2000];
ll ans;

int main()
{
	Init;
	Solution();
	return 0;
}

ll comb(int n,int r){
	if(r>n || r < 0 || n < 0)
		return 0;
	ll res = fac[n];
	res = (res*rfac[r])%mod;
	res = (res*rfac[n-r])%mod;
	return res;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	ll r = ppow(base,exp/2);
	r*=r;
	r%=mod;
	if(exp%2)
		r*=base;
	return r%mod;
}

void prep(){
	fac[0] = 1;
	fori(i,1,1010){
		fac[i] = (i*fac[i-1])%mod;
	}
	rfac[1009] = ppow(fac[1009],mod-2);
	for(ll i = 1008;i > 0;i--){
		rfac[i] = (rfac[i+1]*(i+1))%mod;
	}
	rfac[0] = 1;
	fori(i,1,1001){
		int x = i;
		while(x != 1){
			dp[i]++;
			x = __builtin_popcount(x);
		}
	}
}

ll solve(int i,int cnt){
	if(i >= n.length()){
		return int(cnt == 0); 
	}
	if(cnt == 0)
		return 1;
	if(cnt < 0)
		return 0;
	ll res = 0;
	if(n[i] == '0'){
		return solve(i+1,cnt);
	}
	res += solve(i+1,cnt-1);
	res += comb(n.length()-i-1,cnt);
	return res%mod;
}

void Solution(){
	cin >> n >> k;
	prep();
	if(k==0){
		cout << 1 << endl;
		return;
	}
	fori(i,1,n.length()+1){
		if(dp[i] == k-1){
			ans += solve(0,i);
			ans %= mod;
		}
	}
	if(k==1)
		ans=(ans-1+mod)%mod;
	cout << ans << endl;
}
