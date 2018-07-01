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

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

int n;
string s;
int lps[M]; // i is last index
bool good[M]; // i is lps len
int cn[M],ans[M];;

inline void Solution(){
	cin >> s;
	n = s.length();
	fori(i,1,n){
		lps[i] = lps[i-1];
		while(lps[i] && s[i] != s[lps[i]])
			lps[i] = lps[lps[i]-1];
		if(s[i] == s[lps[i]])
			++lps[i];
	}
	int t = n;
	int gcn = 0;
	while(t){
		good[t] = 1;
		gcn++;
		ans[t] = 0;
		t = lps[t-1];
	}
	forar(i,n){
		++ans[lps[i]];
	}
	ans[n] = 1;
	for(int i = n;i >= 1;--i){
		ans[lps[i-1]] += ans[i];
	}
	cout << gcn << endl;
	fori(i,1,n+1){
		if(good[i]){
			cout << i << " " << ans[i] << endl;
		}
	}
}
