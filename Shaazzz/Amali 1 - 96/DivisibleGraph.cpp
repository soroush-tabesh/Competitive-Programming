//In The Name of Allah
//Sun 3/10/96
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
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e3+100;

void Solution();

int n,m,ans = 10*1000*1000;
int cx,cy;
int par[2][M];
bool mark[2][M];
int dist[2][M];

int main()
{
	Init;
	Solution();
	return 0;
}

inline ll lcm(ull a,ull b){
	ll gcd = __gcd(a,b);
	a/=gcd;
	a*=b;
	return a;
}

void Solution(){
	cin >> n >> m;
	cin >> cx >> cy;
	forar(i,m){
		cin >> par[0][i] >> par[1][i];
		dist[0][i] = dist[1][i] = 10*1000*1000;
	}
	vector<int> toproA;int headA = 0;
	vector<int> toproB;int headB = 0;
	forar(i,m){
		int k = lcm(cx,par[0][i]);
		if(lcm(cx,par[0][i]) <= n)
			toproA.pb(i);
	}
	int d = 1;
	while(headA < toproA.size()){
		while(headA < toproA.size()){
			dist[1][toproA[headA]] = min(d,dist[1][toproA[headA]]);
			if(!mark[1][toproA[headA]]){
				mark[1][toproA[headA]] = 1;
				toproB.pb(toproA[headA]);
			}
			headA++;
		}
		while(headB < toproB.size()){
			forar(i,m){
				if(lcm(par[0][i],par[1][toproB[headB]]) <= n){
					dist[0][i] = min(dist[0][i],d);
					if(!mark[0][i]){
						mark[0][i] = 1; 
						toproA.pb(i);
					}
				}
			}
			headB++;
		}
		d++;
	}
	forar(i,m){
		if(lcm(par[0][i],cy)<=n){
			ans = min (dist[0][i],ans);
		}
		if(lcm(par[1][i],cy)<=n){
			ans = min (dist[1][i],ans);
		}
	}
	if(ans == 10*1000*1000){
		cout << -1 <<endl;
	}else{
		cout << ans << endl;
	}
}
