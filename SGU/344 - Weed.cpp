//In The Name of Allah
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
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

void Solution();

ll n,m;
bool plane[1005][1005];
queue<pll> topro;
pll ways[4] = {{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

bool isweed(pll v){
	if(v.F < 0 || v.F >= n || v.S < 0 || v.S >= m)
		return false;
	return plane[v.F][v.S];
}

bool check(pll v){
	if(v.F < 0 || v.F >= n || v.S < 0 || v.S >= m)
		return false;
	ll cnt = 0;
	forar(i,4)
		if(isweed({v.F+ways[i].F,v.S+ways[i].S}))
			cnt++;
	return (cnt>=2)&&(!isweed(v));
}

void Solution(){
	cin >> n >> m;
	ll ans=0;
	forar(i,n){
		forar(j,m){
			char c;
			cin >> c;
			if(c == 'X'){
				plane[i][j] = 1;
				ans++;
				topro.push({i,j});
			}
		}
	}
	while(!topro.empty()){
		pll cur = topro.front();
		topro.pop();
		forar(i,4){
			if(check({cur.F+ways[i].F,cur.S+ways[i].S})){
				plane[cur.F+ways[i].F][cur.S+ways[i].S] = 1;
				ans++;
				topro.push({cur.F+ways[i].F,cur.S+ways[i].S});
			}
		}
	}
	cout << ans << endl;
}