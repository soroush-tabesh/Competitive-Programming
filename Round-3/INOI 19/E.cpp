//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
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

const ll delta = 10337;

void Solution();

bool cell[6][6];
ll cnt;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	ll v = ppow(base,exp/2);
	v *= v;
	if(exp%2==1)
		v *= base;
	return v;
}

void dfs(int i , int j){
	if(i == 4 && j == 4){
		cnt++;
		return;
	}
	if(cell[i+1][j]){
		dfs(i+1,j);
	}
	if(cell[i][j+1]){
		dfs(i,j+1);
	}
}

void Solution(){
	ll ans = 0;
	forar(i,ppow(2,23)){
		memset(cell,0,sizeof cell);
		cell[0][0] = 1;
		cell[4][4] = 1;
		fori(k,1,24){
			if(i & (1<<(k-1))){
				cell[k/5][k%5] = 1;
			}
		}
		cnt = 0;
		dfs(0,0);
		if(cnt == 1)
			ans++;
	}
	cout << ans%delta << endl;
}