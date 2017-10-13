//In The Name of Allah
//Thu 16/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 3e5+5;

void Solution();

ll n,k,ans;
pll data[M];
ll anslist[M];
set<ll> rem;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> k;
	forar(i,n){
		cin >> data[i].F;
		data[i].S = i+1;
		rem.insert(rem.end(),i+k+1);
	}
	sort(data,data+n,greater<pll>());
	forar(i,n){
		set<ll>::iterator it = rem.lower_bound(data[i].S);
		ans += ((*it) - data[i].S)*data[i].F;
		anslist[data[i].S-1] = *it;
		rem.erase(it);
	}
	cout << ans << endl;
	forar(i,n){
		cout << anslist[i] << " ";
	}
	
}