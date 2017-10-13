//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: kimbits
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("kimbits.in","r",stdin),freopen("kimbits.out","w",stdout)
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

ll cmbdp[33][33];
bool mark[32];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

ll cmb(ll k,ll r){
	if(cmbdp[k][r])
		return cmbdp[k][r];
	if(r == 1 || r == k-1)
		return k;
	if(r == 0 || r == k)
		return 1;
	ll v = cmb(k-1,r) + cmb(k-1,r-1);
	cmbdp[k][r] = v;
	return v;
}

ll prvcmb(ll k,ll r){
	if(r>k)
		r=k;
	ll v = 0;
	forar(i,r+1){
		v += cmb(k,i);
	}
	return v;
}

void solve(ll n,ll c,ll ind ){
	if(ind*c*n == 0)
		return;
	// mark
	ll v = 0;
	ll i;
	for(i = n-1;i >= 0;i--){
		v = prvcmb(i,c)+1;
		if(v <= ind){
			mark[i] = 1;
			break;
		}
	}
	// solve next
	solve(n-1,c-1,ind - v + 1);
}

void Solution(){
	ll n,c,ind;
	cin >> n >> c >> ind;
	solve(n,c,ind);
	while(n){
		n--;
		cout << mark[n];
	}
	cout << endl;
}
