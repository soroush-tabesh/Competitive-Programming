//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: butter
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("butter.in","r",stdin),freopen("butter.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
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
const int M = 100*1000+5;

void Solution();

int ncows,npastures,npaths;
vector<pii> adj[810];
vector<int> cowpos;
set<int> cowpos_set;
int dists[810][810]; // cows' pastures to other pastures
bool mark[810];
int vhind[810];
vector<int> heap;
int cur;
const int inf = 1e7;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void update(int ind){
	vhind[heap[ind]] = ind;
	while(ind > 0 && dists[cur][heap[(ind-1)/2]] > dists[cur][heap[ind]]){ // move up check
		vhind[heap[(ind-1)/2]] = ind;
		vhind[heap[ind]] = (ind-1)/2;
		swap(heap[(ind-1)/2],heap[ind]);
		ind = (ind-1)/2;
	}
	bool left,right;
	while((2*ind+1 < heap.size() && dists[cur][heap[2*ind+1]] < dists[cur][heap[ind]])
			|| (2*ind+2 < heap.size() && dists[cur][heap[2*ind+2]] < dists[cur][heap[ind]])){ // move down check
        bool left = (2*ind+1 < heap.size() && dists[cur][heap[2*ind+1]] < dists[cur][heap[ind]]);
        bool right = (2*ind+2 < heap.size() && dists[cur][heap[2*ind+2]] < dists[cur][heap[ind]]);
		if(left && right){
			if(dists[cur][heap[2*ind+1]] < dists[cur][heap[2*ind+2]]){
				vhind[heap[2*ind+1]] = ind;
				vhind[heap[ind]] = 2*ind+1;
				swap(heap[2*ind+1],heap[ind]);
				ind = 2*ind+1;
			}else{
				vhind[heap[2*ind+2]] = ind;
				vhind[heap[ind]] = 2*ind+2;
				swap(heap[2*ind+2],heap[ind]);
				ind = 2*ind+2;
			}
		}else if(left){
			vhind[heap[2*ind+1]] = ind;
			vhind[heap[ind]] = 2*ind+1;
			swap(heap[2*ind+1],heap[ind]);
			ind = 2*ind+1;
		}else if(right){
			vhind[heap[2*ind+2]] = ind;
			vhind[heap[ind]] = 2*ind+2;
			swap(heap[2*ind+2],heap[ind]);
			ind = 2*ind+2;
		}
	}
}

void add(int x){
	heap.pb(x);
	update(heap.size()-1);
}

void hrem(int ind){
	swap(heap[ind],heap[heap.size()-1]);
	heap.pop_back();
	update(ind);
}

void Solution(){
	cin >> ncows >> npastures >> npaths;
	forar(i,ncows){
		int a;
		cin >> a;
		cowpos.pb(a);
		cowpos_set.insert(a);
	}
	forar(i,npaths){
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}
	forar(i,802){
		forar(j,802){
			dists[i][j] = inf;
		}
	}
	// run dijkstra for each pasture with cow
	for(int orig : cowpos_set){
		memset(mark,0,sizeof mark);
		forar(i,802)
			vhind[i] = -1;
		heap.clear();
		mark[orig] = 1;
		dists[orig][orig] = 0;
		cur = orig;
		for(pii neib : adj[orig]){
			dists[orig][neib.F] = neib.S;
			add(neib.F);
		}
		while(!heap.empty()){
			int topro = heap.front();
			hrem(0);
			mark[topro] = 1;
			for(pii neib : adj[topro]){
				if(mark[neib.F])
					continue;
				dists[orig][neib.F] = min(dists[orig][neib.F],dists[orig][topro] + neib.S);
				if(vhind[neib.F] == -1){
					add(neib.F);
				}else{
					update(vhind[neib.F]);
				}
			}
		}
	}
	int m_min = inf;
	fori(i,1,npastures+1){
		int sum = 0;
		for(int p : cowpos){
			sum += dists[p][i];
		}
		m_min = min (m_min,sum);
	}
	
	cout << m_min << endl;
	
}
