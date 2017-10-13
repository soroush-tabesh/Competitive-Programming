//In The Name of Allah
//Mon 20/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e2+5;

void Solution();

int n;
string data[M];
set<int> adj[30];
bool cycle;
vector<int> res;
bool pmark[30];
bool tmark[30];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void make_graph(int head,int tail,int depth){
	// validate input
	while(head < tail && data[head].length()<=depth){
		head++;
	}
	fori(i,head,tail){
		if(data[i].length()<=depth){
			cycle = true;
			return;
		}
	}
	// make digraph
	fori(i,head,tail-1){
		int nhead = i;
		int ntail = i;
		while(ntail < tail && data[ntail][depth] == data[nhead][depth]){
			ntail++;
		}
		if(ntail - nhead > 1){
			make_graph(nhead,ntail,depth+1);
		}
		i = ntail - 1;
		if(i < tail-1){
			adj[data[i][depth]-'a'].insert(data[i+1][depth]-'a');
		}
	}
}

void toposort(int v){
	pmark[v] = 1;
	tmark[v] = 1;
	for(int neib : adj[v]){
		if(tmark[neib])
			cycle = true;
		if(pmark[neib])
			continue;
		toposort(neib);
	}
	tmark[v] = 0;
	res.pb(v);
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i];
	}
	make_graph(0,n,0);
	forar(i,26){
		if(!pmark[26-i-1])
			toposort(26-i-1);
	}
	reverse(res.begin(),res.end());
	if(cycle){
		cout << "Impossible";
	}else{
		for(int x : res){
			cout << char(x+'a');
		}
	}
	cout << endl;
}

 