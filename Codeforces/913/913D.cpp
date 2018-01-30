//In The Name of Allah
//Mon 18/10/96
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

struct classcomp{
	bool operator()(pll a,pll b){
		return a.F < b.S || (a.F == b.F && a.S > b.S);
	}
};

ll n,t,ans=1;
pll qs[M];
map<pll,int> mpp;
set<pll,classcomp> prc;

int main()
{
	Init;
	Solution();
	return 0;
}

bool comp(pll a,pll b){
	return a.S < b.S || (a.S == b.S && a.F > b.F);
}

void Solution(){
	cin >> n >> t;
	forar(i,n){
		cin >> qs[i].F >> qs[i].S;
		mpp[qs[i]] = i+1;
	}
	sort(qs,qs+n,comp);
	if(qs[0].S > t){
		cout << "0\n0" << endl;
		return;
	}
	prc.insert(qs[0]);
	ll tme = qs[0].S;
	fori(i,1,n){
		ans = max(ans,ll(prc.size()));
		if(prc.size() == prc.begin()->F){
			if(tme - prc.begin()->S + qs[i].S > t){
				break;
			}
			tme -= prc.begin()->S;
			prc.erase(prc.begin());
			prc.insert(qs[i]);
			tme += qs[i].S;
		}else{
			if(qs[i].S + tme > t){
				break;
			}else{
				tme += qs[i].S;
				prc.insert(qs[i]);
			}
		}
	}
	ans = max(ans,ll(prc.size()));
	
	prc.clear();
	prc.insert(qs[0]);
	tme = qs[0].S;
	fori(i,1,n){
		if(prc.size() == ans){
			cout << prc.size() << endl;
			cout << prc.size() << endl;
			for(auto x : prc){
				cout << mpp[x] << " ";
			}
			cout << endl;
			return;
		}
		if(prc.size() == prc.begin()->F){
			if(tme - prc.begin()->S + qs[i].S > t){
				break;
			}
			tme -= prc.begin()->S;
			prc.erase(prc.begin());
			prc.insert(qs[i]);
			tme += qs[i].S;
		}else{
			if(qs[i].S + tme > t){
				break;
			}else{
				tme += qs[i].S;
				prc.insert(qs[i]);
			}
		}
	}
	if(prc.size() == ans){
		cout << prc.size() << endl;
		cout << prc.size() << endl;
		for(auto x : prc){
			cout << mpp[x] << " ";
		}
		cout << endl;
		return;
	}
	
}
