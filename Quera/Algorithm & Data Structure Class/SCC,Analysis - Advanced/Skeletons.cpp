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

int n,m,cntscc,mult,num[M],cntout[M];
vi adjout[M],adjin[M];
bool mark[M];

void init(){
	mult = 0;
	cntscc = 0;
	fori(i,0,n+10){
		adjin[i].clear();
		adjout[i].clear();
		num[i] = 0;
		cntout[i] = 0;
	}
}

void dfsA(int v=0){
	if(mark[v])
		return;
	mark[v] = 1;
	cntscc++;
	for(int neib : adjout[v])
		dfsA(neib);
}

void dfsB(int v=0){
	if(mark[v])
		return;
	mark[v] = 1;
	cntscc++;
	for(int neib : adjin[v])
		dfsB(neib);
}

bool isscc(){
	fill(mark,mark+n,0);
	dfsA();
	fill(mark,mark+n,0);
	dfsB();
	return (cntscc == 2*n);
}

void extend(int v,int dep){
	if(mark[v]){
		if(mult == 0){
			mult = dep - num[v];
		}else{
			mult = __gcd(mult,(dep%mult)-(num[v]%mult)+mult);
		}
	}else{
		mark[v] = 1;
		num[v] = dep;
	}
	while(cntout[v] < adjout[v].size())
		extend(adjout[v][cntout[v]++],dep+1);
}

int32_t main(){
	Init;
	cin >> n >> m;
	while(m != 0 || n != 0){
		init();
		fori(i,0,m){
			int a,b;
			cin >> a >> b;
			adjout[--a].pb(--b);
			adjin[b].pb(a);
		}
		if(!isscc()){
			cout << "N" << endl;
			cin >> n >> m;
			continue;
		}
		fill(mark,mark+n,0);
		extend(0,0);
		if(mult == 1)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
		cin >> n >> m;
	}
	return 0;
}
