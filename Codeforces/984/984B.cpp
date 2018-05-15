//In The Name of Allah
//Tue 25/2/97
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

int32_t main()
{
	Init;
	Solution();
	return 0;
}

int grid[200][200];
int dp[200][200];

inline void Solution(){
	int n,m;
	cin >> n >> m;
	fori(i,1,n+1){
		fori(j,1,m+1){
			char c;
			cin >> c;
			if(c == '*'){
				grid[i][j] = -1;
			}else if (c != '.'){
				grid[i][j] = c-'0';
			}
			if(grid[i][j] == -1){
				fori(i2,-1,2){
					fori(j2,-1,2){
						dp[i+i2][j+j2]++;
					}
				}
			}
		}
	}
	bool is = true;
	fori(i,1,n+1){
		fori(j,1,m+1){
			if(grid[i][j] != -1){
				if(grid[i][j] != dp[i][j])
					is = false;
			}
		}
	}
	cout << (is ? "YES" : "NO") << endl;
}
