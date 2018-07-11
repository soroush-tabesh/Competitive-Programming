//In The Name of Allah
//Tue 15/11/96
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

pll p0;

int main()
{
	Init;
	int t;cin >> t;
	while(t--)
		Solution();
	return 0;
}

inline ll crossp(pll p1,pll p2,pll pv){
	return (p1.F-pv.F)*(p2.S-pv.S) - (p2.F - pv.F)*(p1.S - pv.S);
}

inline ll distsq(pll a , pll b){
	return (a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S);
}

bool comp(pll a,pll b){
	return crossp(a,b,p0) > 0 || (crossp(a,b,p0) == 0 && distsq(a,p0) > distsq(b,p0));
}

inline bool comp2(pll a,pll b){
	return crossp(a,b,p0) == 0;
}

inline bool comp3(pll a,pll b){
	return a.S < b.S || (a.S == b.S && a.F < b.F);
}

inline void Solution(){
	ll n;
	cin >> n;
	vector<pll> p(n);
	forar(i,n){
		cin >> p[i].F >> p[i].S;
	}
	sort(p.begin(),p.end(),comp3); // normal sort first y then x ascending
	p.resize(n = distance(p.begin(),unique(p.begin(),p.end()))); // remove duplicates
	p0 = p[0];
	sort(p.begin()+1,p.end(),comp); // polar sorting ccw
	p.resize(n = distance(p.begin(),unique(p.begin()+1,p.end(),comp2))); // keeping furthest points for equal angles
	if(n<3){
		cout << -1 << endl;
		return;
	}
	vector<pll> st({p[0],p[1],p[2]});
	fori(i,3,n){
		while(crossp(st[st.size()-1],p[i],st[st.size()-2]) <= 0){
			st.pop_back();
		}
		st.pb(p[i]);
	}
	forar(i,st.size()){
		if(i)
			cout << ", ";
		cout << st[i].F << " " << st[i].S;
	}
	cout << endl;
}
