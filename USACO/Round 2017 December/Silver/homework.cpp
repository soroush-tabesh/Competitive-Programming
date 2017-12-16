//In The Name of Allah
//Sat 25/9/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("homework.in","r",stdin),freopen("homework.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define clamp(a,b,i) max(min(i,b),a)
#define infint 1000*1000*1000

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

struct comp{
	bool operator()(pll a,pll b){
		return ((1LL*a.F*b.S) > (1LL*a.S*b.F));
	}
};
ll n,data[M],pref[M],mn[M];
map<pll,vector<ll>,comp> scores;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i];
		pref[i]+=data[i];
		pref[i+1] = pref[i];
	}
	mn[0] = data[n-1];
	forar(i,n-1){
		mn[i+1] = min(mn[i],data[n-2-i]);
	}
	forar(i,n-2){
		pll res;
		res.F = pref[n-1]-pref[i]-mn[n-i-2];
		res.S = n-i-2;
		ll gcd = __gcd(res.F,res.S);
		res.F /= gcd;
		res.S /= gcd;
		scores[res].pb(i+1);
	}
	for(ll x : scores.begin()->S){
		cout << x << endl;
	}
}
