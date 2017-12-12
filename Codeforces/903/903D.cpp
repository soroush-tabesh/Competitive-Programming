//In The Name of Allah
//Tue 21/9/96
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

ll n;
map<int,int> rmap;
vector<ll> data;

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		ll a;
		cin >> a;
		rmap[a]++;
		data.pb(a);
	}
	ll sum = 0,pref=0;
	forar(i,n){
		sum += (i*data[i])-pref;
		pref+=data[i];
	}
	for(ll x : data){
		rmap[x]--;
		sum -= rmap[x+1]-rmap[x-1];
	}
	cout << sum << endl;
}
