//In The Name of Allah
//Tue 30/3/97
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fori(i,a,b) for(ll i = a; i < b;i++)
#define forar(i,n) fori(i,0,n)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LSB(x) (x&(-x))

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

ll n,k,ans,smf;
ll f[3000];
ll compid[3000];
vector<int> comp[3000];
ll comfount[3000];
set<pair<ll,pll> > lst;
ll cons;

int32_t main()
{
	Init;
	int _t;
	cin >> _t;
	while(_t--)
		Solution();
	return 0;
}

inline void Solution(){
	cin >> n >> k;
	smf = 0;
	lst.clear();
	forar(i,n){
		cin >> f[i];
		compid[i] = i;
		comp[i].clear();
		comp[i].pb(i);
		comfount[i] = f[i];
		smf += f[i];
	}
	forar(i,n){
		forar(j,n){
			ll a;
			cin >> a;
			if(i < j){
				lst.emplace(a,mp(i,j));
			}
		}
	}
	ans = smf;
	forar(t,n-1){
		while(compid[lst.begin()->S.F] == compid[lst.begin()->S.S]){
			lst.erase(lst.begin());
		}
		int a = lst.begin()->S.S;
		int b = lst.begin()->S.F;
		cons += lst.begin()->F;
		lst.erase(lst.begin());
		if(comp[compid[a]].size() < comp[compid[b]].size()){
			smf -= comfount[compid[a]] + comfount[compid[b]];
			int ta = compid[a];
			for(int x : comp[ta]){
				compid[x] = compid[b];
				comp[compid[b]].pb(x);
			}
			comfount[compid[b]] = min(comfount[compid[b]],comfount[ta]);
			smf += comfount[compid[b]];
		}else{
			smf -= comfount[compid[a]] + comfount[compid[b]];
			int tb = compid[b];
			for(int x : comp[tb]){
				compid[x] = compid[a];
				comp[compid[a]].pb(x);
			}
			comfount[compid[a]] = min(comfount[compid[a]],comfount[tb]);
			smf += comfount[compid[a]];
		}
		if(n - t <= k){
			ans = min(ans,smf+cons);
		}
	}
	cout << ans << endl;
}
