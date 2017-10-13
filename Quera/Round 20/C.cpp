//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("shopping.in","r",stdin),freopen("shopping.out","w",stdout)
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

vector<int> adj[100*1000+5];
bool mark[100*1000+5];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

int dist(int s,int e){
	if(s == e)
		return 0;
	mark[s] = 1;
	for(int neib : adj[s]){
		if(!mark[neib]){
			int temp = dist(neib,e);
			if(temp != -1){
				return temp+1;
			}
		}
	}
	return -1;
}

void Solution(){
	int n;
	cin >> n;
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int s,e;
	cin >> s >> e;
	s--;
	e--;
	int ans = dist(s,e);
	//Log(ans);
	if(ans % 2 == 1){
		cout << "karakter e komaki_2";
	}else{
		cout << "karakter e komaki_1";
	}
}
