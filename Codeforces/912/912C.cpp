//In The Name of Allah
//Fri 15/10/96
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

const ll mod = 1e9+7,M = 1e5+100;

void Solution();

struct Enemy{
	ll mx_hlth,st_hlth,regen;
	vector<pll> upds; // time - health
};typedef struct Enemy Enemy;

ll n,m,bnt,inc,dmg;
vector<Enemy> enem[M];


int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> m;
	cin >> bnt >> inc >> dmg;
	forar(i,n){
		cin >> enem[i].mx_hlth >> enem[i].st_hlth >> enem[i].regen;
	}
	forar(i,m){
		ll t,e,h;
		cin >> t >> e >> h;
		e--;
		enem[e].upds.emplace_back(t,h);
	}
	forar(i,n){
		if(enem[i].mx_hlth <= dmg){
			cout << -1 << endl;
			return;
		}
		sort(enem[i].upds.begin(),enem[i].upds.end());
	}
}
