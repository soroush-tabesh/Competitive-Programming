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
map<string,int> conv;
int cnt;

int main()
{
	Init;
	int _t;
	cin >> n;
	Solution();
	return 0;
}

void Solution(){
    if(n == 0)
		return;
	cout << "Case " << ++cnt << ": ";
	edges.clear();
	conv.clear();
	forar(i,n){
		string s;
		cin >> s;
		conv[s] = i;
		dist[i] = 0;
	}
	// Bellman-Ford approach(for training purpose)
	// A better solution is Floyd-Warshall using conversion ratio as distance while each dist[i][i] is initially one and zero for non-adjacent vertices
	dist[0] = 1;
	cin >> m;
	forar(i,m){
		string a,b;
		ld d;
		cin >> a >> d >> b;
		edges.emplace_back(mp(conv[a],conv[b]),d);
	}
	forar(i,n){
		forar(j,m){
			dist[edges[j].F.S] = max(dist[edges[j].F.S],dist[edges[j].F.F]*edges[j].S);
		}
	}
	bool is = false;
	forar(i,m){
		is |= (dist[edges[i].F.S]<dist[edges[i].F.F]*edges[i].S);
	}
	cout << (is ? "Yes" : "No") << endl;
	cin >> n;
	Solution();
}
