//In The Name of Allah
//Sun 21/8/96
#include<bits/stdc++.h>

#define fori(i,a,b) for(int i = a;i < b;i++)
#define pb push_back 
#define mp make_pair
#define Init ios_base::sync_with_stdio(false),cin.tie(0)
#define F first
#define S second

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const ll M = 1e5+100;

int n,m;
vi adjout[M],adjin[M],postord;
bool mark[M],loop[M];
int comp[M],compsize[M],bucket[M],compcnt;

void dfsB(int v,int c){
	if(comp[v])
		return;
	comp[v] = c;
	compsize[c]++;
	bucket[c] = v;
	for(int neib : adjin[v]){
		dfsB(neib,c);
	}
}

void dfsA(int v){
	if(mark[v])
		return;
	mark[v] = 1;
	for(int neib : adjout[v]){
		dfsA(neib);
	}
	postord.pb(v);
}

void init(){
	postord.clear();
	fori(i,0,n+10){
		adjin[i].clear();
		adjout[i].clear();
		mark[i] = 0;
		loop[i] = 0;
		comp[i] = 0;
		compsize[i] = 0;
		bucket[i] = 0;
	}
	compcnt = 0;
}

int32_t main(){
	Init;
	cin >> n >> m;
	while(m != 0 || n != 0){
		init();
		fori(i,0,m){
			int a,b;
			cin >> a >> b;
			a--;b--;
			if(a == b){
				loop[a] = 1;
				continue;
			}
			adjout[a].pb(b);
			adjin[b].pb(a);
		}
		fori(i,0,n){
			dfsA(i);
			//if(adjout[i].empty())
			//	loop[i] = 1;
		}
		fori(i,0,n){
			if(!comp[postord[n-i-1]]){
				dfsB(postord[n-i-1],++compcnt);
			}
		}
		bool ans = true;
		fori(i,1,compcnt+1){
			if(compsize[i] == 1 && !loop[bucket[i]]){
				ans = false;
			}
		}
		cout << (ans ? "Y":"N") << endl;
		cin >> n >> m;
	}
	return 0;
}
