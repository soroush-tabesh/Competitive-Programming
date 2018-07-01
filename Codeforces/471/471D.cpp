//In The Name of Allah
//Tue 6/4/97
#pragma GCC optimize "-Ofast"
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
#define fori(i,a,b) for(ll i = a; i < b;i++)
#define forar(i,n) fori(i,0,n)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LSB(x) (x&(-x))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n,m;
int lps[M]; // length of longest prefsuf when last index of current is i
int pat[M],seq[M];

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

inline void Solution(){
	cin >> n >> m;
	int lst;
	if(n < m){
		cout << 0 << endl;
		return;
	}
	if(m == 1){
		cout << n << endl;
		return;
	}
	forar(i,n){
		int a;
		cin >> a;
		if(i)
			seq[i-1] = a-lst;
		lst = a;
	}
	forar(i,m){
		int a;
		cin >> a;
		if(i)
			pat[i-1] = a-lst;
		lst = a;
	}
	--n;--m;
	// calculate lps for pat
	fori(i,1,m){
		lps[i] = lps[i-1];
		while(lps[i] && pat[lps[i]] != pat[i]){
			lps[i] = lps[lps[i]-1];
		}
		if(pat[lps[i]] == pat[i])
			++lps[i];
	}
	int ans = 0;
	// calculate occurances
	int pt = 0;
	forar(i,n){
		while(pt && pat[pt] != seq[i]){
			pt = lps[pt-1];
		}
		if(pat[pt] == seq[i])
			pt++;
		if(pt == m){
			ans ++;
			pt = lps[pt-1];
		}
	}
	cout << ans << endl;
}
