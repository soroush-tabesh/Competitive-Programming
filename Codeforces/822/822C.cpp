//In The Name of Allah
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

void Solution();

struct vch{
	ll cost,l,r,id;
	bool operator<(vch rh) const{
		return (cost<rh.cost) || (cost == rh.cost && l < rh.l);
	}
};

map<ll,map<ll,set<vch> > > vouchers; // map[duration] -> map[start_time] -> set of best prices
ll n,x,ans=1e10;

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
	cin >> n >> x;
	forar(i,n){
		vch t;
		cin >> t.l >> t.r >> t.cost;
		t.id = i;
		vouchers[t.r-t.l+1].insert(t);
	}
	
	for(pair<ll,map<ll,set<vch> > > m_cur : vouchers){
		if(cur.F >= x || cur.F > (x+1)/2)
			break;
		map<ll,set<vch> > cur = m_cur.S;
		map<ll,set<vch> > curcmpl = vouchers[x-cur.F];
		if(curcmpl.size() == 0)
			continue;
		for(map<ll,set<vch> > m_lset : cur){
			set<vch> lset = m_lset.S;
			// check behind
			for(map<ll,set<vch> > m_lset2 : curcmpl){
				set<vch> lset2 = m_lset2.S;
				if(m_lset2.F + x - cur.F >= cur.F)
					break;
				
			}
			// check front
		}
	}
	if(ans != 1e10)
		cout << ans;
	else
		cout << -1;
	
}


