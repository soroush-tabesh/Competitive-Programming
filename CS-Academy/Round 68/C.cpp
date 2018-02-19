//In The Name of Allah
//Wed 18/11/96
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

struct classcomp{
	bool operator()(const pll &a,const pll &b) const{
		return a.S*b.F < a.F*b.S || (a.S*b.F == a.F*b.S && a.F < b.F);
	}
};
template <typename T> using ordered_set =
tree<T, null_type, classcomp, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	int n;
	cin >> n;
	vector<pair<pll,int> > points;
	vector<int> ans(n);
	forar(i,n){
		int a,b;
		cin >> a >> b;
		points.emplace_back(mp(a,b),i);
	}
	sort(points.begin(),points.end());
	ordered_set<pll> prpn;
	forar(i,n){
		prpn.insert(points[i].F);
		ans[points[i].S] = prpn.order_of_key(points[i].F);
	}
	for(int x : ans){
		cout << x << endl;
	}
}
