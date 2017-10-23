//In The Name of Allah
//Tue 25/7/96
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

const ll mod = 1e9+7,M = 3e5+5;

void Solution();

ll n,ans;
bool data[M];
ll fen1[M];
ll fen2[M];
const ll fenbase = 100*1000+500;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void add_suf(ll x, ll val)
{
	x += fenbase;
    for (ll i = x + 1; i < M; i += i & (-i)) fen1[i] += val;
}

ll get_suf(ll x)
{
	x += fenbase;
    ll ans = 0;
    for (ll i = x; i > 0; i -= i & (-i)) ans += fen1[i];
    return ans;
}

ll sum_suf(ll x, ll y)
{
    return get_suf(y) - get_suf(x);
}

void add_pre(ll x, ll val)
{
	x += fenbase;
    for (ll i = x + 1; i < M; i += i & (-i)) fen2[i] += val;
}

ll get_pre(ll x)
{
	x += fenbase;
    ll ans = 0;
    for (ll i = x; i > 0; i -= i & (-i)) ans += fen2[i];
    return ans;
}

ll sum_pre(ll x, ll y)
{
    return get_pre(y) - get_pre(x);
}

void Solution(){
	cin >> n;
	forar(i,n){
		char c;
		cin >> c;
		if(c=='1')
			data[i]=1;
	}
	ll bal = 0;
	ll balrev = 0;
	forar(i,n){
		balrev += (data[n-i-1] ? 1 : -1);
		add_suf(balrev,1);
	}
	forar(i,n){
		add_suf(balrev,-1);
		balrev -= (data[i] ? 1 : -1);
		add_pre(bal,1);
		bal += (data[i] ? 1 : -1);
		ans += sum_pre(-n-1,bal);
		ans += sum_suf(-bal+1,n+1);
	}
	cout << ans << endl;
	
}
