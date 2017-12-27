//In The Name of Allah
//Wed 6/10/96
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

const ll mod = 1e9+7,M = 1e5+100;

void Solution();

int n,m,deps[M],cnt,ans;
bool state[M];
bool mark[M];
vector<int> adjin[M],adjout[M];

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> m;
	forar(i,n){
		int a;
		cin >> a;
		if(a)
			state[i]=1;
	}
	forar(i,m){
		int a,b;
		cin >> b >> a;
		adjout[a].pb(b);
		adjin[b].pb(a);
	}
	vector<int> ms;int headms=0;
	vector<int> cs;int headcs=0;
	forar(i,n){
		if(adjin[i].empty()){
			if(state[i]){
				cs.pb(i);
			}else{
				ms.pb(i);
			}
		}
	}
	while(cnt < n){
		while(headms < ms.size()){
			int v = ms[headms++];
			cnt++;
			for(int neib : adjout[v]){
				deps[neib]++;
				if(deps[neib] >= adjin[neib].size()){
					if(state[neib]){
						cs.pb(neib);
					}else{
						ms.pb(neib);
					}
				}
			}
		}
		if(headcs < cs.size()){
			ans++;
		}
		while(headcs < cs.size()){
			int v = cs[headcs++];
			cnt++;
			for(int neib : adjout[v]){
				deps[neib]++;
				if(deps[neib] >= adjin[neib].size()){
					if(state[neib]){
						cs.pb(neib);
					}else{
						ms.pb(neib);
					}
				}
			}
		}
	}
	cout << ans << endl;
}
