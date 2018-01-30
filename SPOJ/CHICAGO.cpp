//In The Name of Allah
//Fri 10/11/96
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

int n,m;
ld dist[100];
vector<pair<pii,ld> > edges;

int main()
{
	Init;
	cin >> n;
	Solution();
	return 0;
}

void Solution(){
    if(n == 0)
		return;
	edges.clear();
	dist[0] = 1;
	forar(i,n-1){
		dist[i+1] = 0;
	}
	cin >> m;
	forar(i,m){
		int a,b;
		ld d;
		cin >> a >> b >> d;
		edges.pb(mp(mp(--a,--b),d/100.0));
	}
	forar(i,n){
		forar(j,m){
			dist[edges[j].F.S] = max(dist[edges[j].F.S],dist[edges[j].F.F]*edges[j].S);
			dist[edges[j].F.F] = max(dist[edges[j].F.F],dist[edges[j].F.S]*edges[j].S);
		}
	}
	cout << fixed << setprecision(6);
	cout << dist[n-1]*100 << " percent" << endl;
	cin >> n;
	Solution();
}
