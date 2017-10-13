//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll delta = 10957;

void Solution();
void SolutionB();

int init[5001][10];
int val[30];
int mx[5001][5001];
ll dpcomb[5001][5001];

int main()
{
	Init;
	//WFile;
	//Solution();
	SolutionB();
	return 0;
}

int getval(int v){
	if(val[v] != -1)
		return val[v];
	int res = (getval(v/2) + getval(v-1) + 1) % 100;
	val[v] = res;
	return res;
}

int dfs(int i,int j){
	if(mx[i][j] != -1)
		return mx[i][j];
	if(i == 5){
		mx[i][j] = val[init[i+1][j]] + val[init[i+1][j+1]] + val[init[i][j]];
		return mx[i][j];
	}
	int t1 = dfs(i+1,j) + val[init[i+1][j+1]] + val[init[i][j]];
	int t2 = dfs(i+1,j+1) + val[init[i+1][j]] + val[init[i][j]];
	mx[i][j] = max(t1,t2);
	return mx[i][j];
}

void Solution(){
	int tkin = 28;
	forar(i,7){
		forar(j,i+1){
			init[i][j] = tkin;
			tkin--;
		}
	}
	forar(i,30){
		val[i] = -1;
	}
	val[1] = delta%10;
	fori(i,2,29){
		val[i] = getval(i);
	}
	forar(i,7){
		forar(j,7){
			mx[i][j] = -1;
		}
	}
	dfs(0,0);
	cout << mx[0][0];
}

ll combine(int n,int r){
	if(r < 0 || n < 0)
		return 0;
	if(n == r || r == 0)
		return 1;
	if(r > n)
		return 0;
	if(dpcomb[n][r] != 0)
		return dpcomb[n][r];
	ll v = combine(n-1,r) + combine(n-1,r-1);
	v%=delta;
	dpcomb[n][r] = v;
	return v;
}

void SolutionB(){
	ll ans = 0;
	forar(i,5000){
		ans += combine(i,(i/2)+1);
		ans += combine(i,(i/2));
		ans %= delta;
		cout << ans << " " << i << endl;
	}
	cout << ans << endl;
}