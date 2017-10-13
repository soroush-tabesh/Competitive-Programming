//In The Name of Allah
//Fri 21/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e2+5;

void Solution();

int n,ans;
bool adj[M][M];
int deg[M];
bool party[M];


int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

inline void toggle(vector<int> prc){
	fori(i,0,prc.size()){
		fori(j,i+1,prc.size()){
			adj[prc[i]][prc[j]] = adj[prc[j]][prc[i]] = !adj[prc[i]][prc[j]];
		}
	}
}

void solve(){
	int tar = -1;
	forar(i,n){
		if(deg[i] % 2){
			tar = i;
			break;
		}
	}
	if(tar != -1){
		vector<int> nb;
		forar(i,n){
			if(adj[tar][i]){
				nb.pb(i);
				adj[tar][i]=0;
				adj[i][tar]=0;
				deg[tar]--;
				deg[i]--;
			}
		}
		toggle(nb);
		solve();
		toggle(nb);
		for(int neib : nb){
			adj[tar][neib] = 1;
			adj[neib][tar] = 1;
			deg[tar]++;
			deg[neib]++;
		}
		int cnt1 = 0;
		forar(i,n)
			if(adj[tar][i] && party[i])
				cnt1++;
		if(cnt1%2 == 0)
			ans += (party[tar] = 1);
	}
	
}

void Solution(){
	cin >> n;
	forar(i,n){
		int c;
		cin >> c;
		deg[i] = c;
		forar(j,c){
			int a;
			cin >> a;
			adj[i][--a]=1;
		}
	}
	solve();
	cout << ans << endl;
	forar(i,n){
		if(party[i])
			cout << i+1 << " ";
	}
	cout << endl;
}
