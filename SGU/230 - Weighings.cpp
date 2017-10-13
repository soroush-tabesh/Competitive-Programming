//In The Name of Allah
//Sat 28/5/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
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

int n,m;
vector<int> adjout[105];
vector<int> toporder;
int ans[105];
bool mark[105];
bool isparent[105];
bool isdag = true;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void toposort(int v){
	mark[v] = 1;
	isparent[v] = 1;
	for(int neib : adjout[v]){
		if(isparent[neib])
			isdag = false;
		if(mark[neib])
			continue;
		toposort(neib);
	}
	isparent[v] = 0;
	toporder.pb(v);
}

void Solution(){
	cin >> n >> m;
	forar(i,m){
		int a,b;
		cin >> a >> b;
		adjout[--b].pb(--a);
	}
	forar(i,n){
		if(!mark[i])
			toposort(i);
	}
	if(!isdag){
		cout << "No solution" << endl;
		return;
	}
	forar(i,n){
		ans[toporder[i]] = i+1;
	}
	forar(i,n){
		cout << ans[i] << " ";
	}
	cout << endl;
}

