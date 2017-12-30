//In The Name of Allah
//Fri 8/10/96
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

ll ik,pra,prb;
bool mark[1500][1500];
ll dp[1500][1500];

int main()
{
	Init;
	Solution();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp <= 0)
		return 1;
	ll res = ppow(base,exp/2);
	res = (res*res)%mod;
	if(exp%2)
		res = (res*base)%mod;
	return res;
}

ll getans(ll k,ll na){
	if(k<=0)
		return 0;
	if(mark[k][na])
		return dp[k][na];
	mark[k][na] = 1;
	if(na <= 0)
		dp[k][na] = (((getans(k,1)*pra)%mod)*ppow((mod+1-prb)%mod,mod-2))%mod;
	else if(na >= k)
		dp[k][na] = (((pra*prb)%mod)*ppow((mod+1-pra)%mod,2*mod-4)+na)%mod;
	else
		dp[k][na] = ((pra*getans(k,na+1))%mod+(prb*((getans(k-na,na)+na)%mod))%mod)%mod;
	return dp[k][na];
}

void Solution(){
	cin >> ik >> pra >> prb;
	ll mul = ppow(pra+prb,mod-2);
	pra = (pra*mul)%mod;
	prb = (prb*mul)%mod;
	cout << getans(ik,0) << endl;
}
