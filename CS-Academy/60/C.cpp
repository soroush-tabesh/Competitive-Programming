//In The Name of Allah
//Wed 15/9/96
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

int n,m,k,res[M];
vector<int> data[M],adjout[M],adjin[M],topo;
bool mark[M],ispar[M],islead[M],isdag = true;

int main()
{
	Init;
	Solution();
	return 0;
}

void make_graph(int beg,int en,int curm){
	if(curm >= m || en-beg <= 1 || en > n)
		return;
	int a=beg,b=beg+1;
	while(b < en){
		if(data[b][curm] == data[a][curm]){
			b++;
		}else{
			make_graph(a,b,curm+1);
			adjout[data[a][curm]].pb(data[b][curm]);
			a=b;
			b++;
		}
	}
	make_graph(a,b,curm+1);
}

void toposort(int v){
	if(mark[v])
		return;
	mark[v] = 1;
	ispar[v] = 1;
	for(int neib : adjout[v]){
		if(ispar[neib]){
			isdag = false;
			return;
		}
		toposort(neib);
	}
	ispar[v] = 0;
	topo.pb(v);
}

void Solution(){
	cin >> n >> k >> m;
	forar(i,n){
		forar(j,m){
			int a;
			cin >> a;
			if(j == 0)
				islead[a] = 1;
			data[i].pb(a);
		}
		if(i){
			bool is = true;
			forar(j,m){
				if(data[i][j] != data[i-1][j])
					is = false;
			}
			if(is)
				isdag = false;
		}
	}
	make_graph(0,n,0);
	forar(i,k){
		toposort(i);
	}
	if(!isdag){
		cout << -1 << endl;
		return;
	}
	reverse(topo.begin(),topo.end());
	if(islead[topo[0]]){
		int tar = -1;
		forar(i,k){
			if(!islead[i] && adjin[i].empty()){
				tar = i;
				break;
			}
		}
		if(tar == -1){
			cout << -1 << endl;
			return;
		}
		topo.erase(find(topo.begin(),topo.end(),tar));
		topo.insert(topo.begin(),tar);
	}
	forar(i,k){
		res[topo[i]] = i;
	}
	forar(i,k){
		cout << res[i] << " ";
	}
	cout << endl;
}
