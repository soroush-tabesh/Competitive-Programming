//In The Name of Allah
//Fri 14/2/97
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

bool grid[52][52];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	int h,w;
	cin >> h >> w;
	fori(i,1,h+1){
		fori(j,1,w+1){
			char c;
			cin >> c;
			grid[i][j] = c=='#';
		}
	}
	bool ans = true;
	fori(i,1,h+1){
		fori(j,1,w+1){
			ans &= !grid[i][j] || grid[i-1][j] || grid[i+1][j] || grid[i][j+1] || grid[i][j-1];
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
}
