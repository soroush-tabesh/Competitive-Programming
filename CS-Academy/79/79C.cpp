//In The Name of Allah
//Wed 19/2/97
#pragma GCC optimize "-O3"
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

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
using namespace __gnu_pbds;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

ll n,k;
template <typename T> using ordered_set =
tree<T, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set<ll> rems;

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline ll binom(ll m){
	return ((m-1)*m)/2;
}

void solve(ll dep,ll invs){
	if(dep == n)
		return;
	if(binom(n-dep-1)>=invs){
		int t = *rems.begin();
		rems.erase(rems.begin());
		cout << t << ' ';
		solve(dep+1,invs);
	}else{
		auto x = rems.find_by_order(invs - binom(n-dep-1));
		int t = *x;
		rems.erase(x);
		cout << t << ' ';
		solve(dep+1,binom(n-dep-1));
	}
}

inline void Solution(){
	cin >> n >> k;
	forar(i,n){
		rems.insert(i+1);
	}
	solve(0,k);
}
