//In The Name of Allah
//Sun 23/2/97
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

int grid[2000][2000];
int dp[2000][2000];
bool mark[2000][2000];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

ll dfs(int i,int j){
	if(mark[i][j])
		return dp[i][j];
	mark[i][j] = 1;
	return dp[i][j] = max(dfs(i+1,j),dfs(i+1,j+1)) + grid[i][j];
}

inline void Solution(){
	int rw;
	cin >> rw;
	forar(i,rw){
		forar(j,i+1){
			cin >> grid[i][j];
		}
	}
	forar(i,rw+1){
		mark[rw][i] = 1;
	}
	cout << dfs(0,0) << endl;
}
