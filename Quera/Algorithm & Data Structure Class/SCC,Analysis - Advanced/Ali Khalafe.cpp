// In The Name of Allah
// Mon 22/8/96
#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef pair<int,int> pii;

const int M = 1e6+10;
int n,m,ans,last = -1;
vector<pii> adjout[M];
bool mark[M];
pii par[M];

void dfs(int v,int pr,int num=0){
	if(mark[v])
		return;
	mark[v] = 1;
	par[v] = make_pair(pr,num);
	for(pii neib : adjout[v])
		dfs(neib.first,v,neib.second);
	if(last != -1 && par[last].first == v)
		ans = par[toporder.back()].second;
	last = v;
}

int main(){
	ios_base::sync_with_stdio(false),cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >> b;
		adjout[--a].pb(make_pair(--b,i));
	}
	for(int i = 0;i < n;i++)
		dfs(i,i);
	cout << 1 << endl << ans+1 << endl;
	return 0;
}