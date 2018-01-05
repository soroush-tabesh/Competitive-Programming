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

struct comp{
	bool operator()(pair<ll,pll> a,pair<ll,pll> b){
		return (a.F > b.F) || (a.F == b.F && a.S > b.S);
	}
};
ll n,m,r,k; // n = x,m = y
ld sum;
set<pair<ll,pll> ,comp> mxs; // cnt - coord
set<pll> prc;
pll ways[4] = {{-1,0},{1,0},{0,-1},{0,1}};

int main()
{
	Init;
	Solution();
	return 0;
}

inline ll getcnt(ll px,ll py){
	px = min(max(px,1LL),n);
	py = min(max(py,1LL),m);
	ll cx = min(n-r+1,px)-max(px-r+1,1LL)+1;
	ll cy = min(m-r+1,py)-max(py-r+1,1LL)+1;
	return cy*cx;
}

inline bool isprc(ll px,ll py){
	px = min(max(px,1LL),n);
	py = min(max(py,1LL),m);
	return prc.find(mp(px,py))!=prc.end();
}

inline void checkways(ll px ,ll py){
	px = min(max(px,1LL),n);
	py = min(max(py,1LL),m);
	forar(w,4){
		if(!isprc(px+ways[w].F,py+ways[w].S)){
			mxs.insert(mp(getcnt(px+ways[w].F,py+ways[w].S),mp(px+ways[w].F,py+ways[w].S)));
		}
	}
}

void Solution(){
	cin >> n >> m >> r >> k;
	k--;
	sum += getcnt((n+1)/2,(m+1)/2);
	prc.insert(mp((n+1)/2,(m+1)/2));
	checkways((n+1)/2,(m+1)/2);
	while(k--){
		auto cur = *mxs.begin();
		mxs.erase(mxs.begin());
		sum += cur.F;
		prc.insert(cur.S);
		checkways(cur.S.F,cur.S.S);
	}
	ld sz = (n-r+1)*(m-r+1);
	sum /= sz;
	cout << fixed << setprecision(15);
	cout << sum << endl;
}
