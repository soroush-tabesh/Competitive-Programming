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

bool board[110][110];
ll n,m;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> m;
	ll um=200,dm=-1,lm=200,rm=-1;
	forar(i,n){
		forar(j,m){
			char c;
			cin >> c;
			if(c == 'B'){
				board[i][j] = 1;
				um = min(i,um);
				dm = max(i,dm);
				lm = min(j,lm);
				rm = max(j,rm);
			}
		}
	}
	if(um == 200){
		cout << 1;
		return;
	}
	
	ll ans = 0;
	// check orientation
	if(dm - um > rm - lm){ // port
		if(dm-um+1 > min(n,m)){
			cout << -1;
			return;
		}
		ll size = dm-um+1;
		ll t = 1e9;
		fori(sqjm,max(0LL,rm-size+1),min(lm,m-size)+1){
			ll tempcnt = 0;
			fori(i,um,dm+1){
				fori(j,sqjm,sqjm+size){
					if(!board[i][j])
						tempcnt++;
				}
			}
			t = min(t,tempcnt);
		}
		ans = t;
	}else if(dm - um < rm - lm){ // land
		if(rm - lm+1 > min(n,m)){
			cout << -1;
			return;
		}
		ll size = rm - lm+1;
		ll t = 1e9;
		fori(sqim,max(0LL,dm-size+1),min(um,n-size)+1){
			ll tempcnt = 0;
			fori(j,lm,rm+1){
				fori(i,sqim,sqim+size){
					if(!board[i][j])
						tempcnt++;
				}
			}
			t = min(t,tempcnt);
		}
		ans = t;
	}else{ // square
		fori(i,um,dm+1){
			fori(j,lm,rm+1){
				if(!board[i][j])
					ans++;
			}
		}
	}
	cout << ans;
	
}