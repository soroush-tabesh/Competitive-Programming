//In The Name of Allah
//Fri 8/10/96
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
char gr[55][55];
string prog;
string perm = "dlru";
pii st,en;

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> m;
	forar(i,n){
		forar(j,m){
			cin >> gr[i][j];
			if(gr[i][j] == 'S'){
				st.F = i;st.S = j;
			}
			if(gr[i][j] == 'E'){
				en.F = i;en.S = j;
			}
		}
	}
	cin >> prog;
	int ans = 0;
	do{
		pii cur = st;
		bool is = false;
		for(char c : prog){
			switch(perm[c-'0']){
				case 'u':
					cur.F--;
				break;
				case 'd':
					cur.F++;
				break;
				case 'l':
					cur.S--;
				break;
				case 'r':
					cur.S++;
				break;
			}
			if(cur.F >= n || cur.F < 0 || cur.S >= m || cur.S < 0 || gr[cur.F][cur.S] == '#'){
				is = false;
				break;
			}
			if(cur == en){
				is = true;
				break;
			}
		}
		if(is)
			ans++;
	}while(next_permutation(perm.begin(),perm.end()));
	cout << ans << endl;
}
