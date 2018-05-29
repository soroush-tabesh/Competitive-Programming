//In The Name of Allah
//Thu 31/2/97
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

int n,m;
bool mat[3000][3000];
int rep[3000];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n;
	cin >> m;
	forar(i,n){
		forar(j,m){
			char c;
			cin >> c;
			mat[i][j] = (c=='1');
			if(c=='1')
				++rep[j];
		}
	}
	forar(i,n){
		bool is = true;
		forar(j,m){
			if(mat[i][j] == 1 && rep[j] < 2)
				is = false;
		}
		if(is){
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	
}
