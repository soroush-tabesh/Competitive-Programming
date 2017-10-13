//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: game1
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("game1.in","r",stdin),freopen("game1.out","w",stdout)
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

int board[105];
pii dp[105][105];
int n;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

pii solve(int a, int b){
	if(dp[a][b] == make_pair(0,0)){
		if((n % 2 == 0 && (b-a+1)%2 == 0) || (n % 2 == 1 && (b-a+1)%2 == 1)){ // Player #1
			if(b == a){
				dp[a][b] = {board[a],0};
			}else{
				pii l,r;
				l = solve(a+1,b);
				l.F += board[a];
				r = solve(a,b-1);
				r.F += board[b];
				if(l.F > r.F || (l.F == r.F && l.S < r.S)){
					dp[a][b] = l;
				}else{
					dp[a][b] = r;
				}
			}
		}else{ // Player #2
			if(b == a){
				dp[a][b] = {0,board[a]};
			}else{
				pii l,r;
				l = solve(a+1,b);
				l.S += board[a];
				r = solve(a,b-1);
				r.S += board[b];
				if(l.S > r.S || (l.S == r.S && l.F < r.F)){
					dp[a][b] = l;
				}else{
					dp[a][b] = r;
				}
			}
		}
	}
	return dp[a][b];
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> board[i];
	}
	pii ans = solve(0,n-1);
	cout << ans.F << " " << ans.S << endl;
}
