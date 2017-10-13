#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
#define pf push_front
#define fr first
#define sc second

using namespace std;

typedef long long int ll;
typedef long double ld;

void solution();

int n;
map<int,vector<int> > verts;
bool mark[100001];

int main(){
	Init;
	solution();
	return 0;
}

ll dfs(int vert){
	ll ans = 1;
	mark[vert] = 1;
	vector<int> neibs = verts[vert];
	for(int i = 0;i < neibs.size();i++){
		if(mark[neibs[i]])
			continue;
		ans *= dfs(neibs[i]);
		ans %= 1000*1000*1000+7;
	}
	return ans+1;
}

void solution(){
	cin >> n;
	for(int i = 0;i < n-1;i++){
		int a,b;
		cin >> a >> b;
		verts[a].pb(b);
		verts[b].pb(a);
	}
	cout << dfs(1);
}
