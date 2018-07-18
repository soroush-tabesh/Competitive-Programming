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

const ll delta = 10259;

void SolutionA();

ll cap[101][101];
ll bacs[101][101];
ll tbacs[101][101];
ll n;
ll day;
ll m1,m2;
bool issat[101][101];
ll sattime[101][101];

int main()
{
	Init;
	//WFile;
	SolutionA();
	return 0;
}


ll ppow(ll base,ll exp,bool usedelta,ll mod){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	ll v = ppow(base,exp/2,usedelta,mod);
	v*=v;
	if(exp % 2 == 1)
		v*=base;
	if(usedelta)
		v%=mod;
	return v;
}

ll getcap(ll i,ll j){
	if(cap[i][j] != 0)
		return cap[i][j];
	ll res = ppow(7,i,true,m1);
	res *= ppow(3,j,true,m1);
	res %= m1;
	res += m2;
	cap[i][j] = res;
	return res;
}

void addbac(ll i,ll j){
	if(i <= 0 || j <= 0 || i > n || j > n)
		return;
	if(!issat[i][j]){
		tbacs[i][j]++;
	}
}

void SolutionA(){
	n = 40;
	m1 = 99991;
	m2 = 10000;
	ll ans = 0;
	bacs[1][1] = 1;
	bacs[1][n] = 1;
	bacs[n][1] = 1;
	bacs[n][n] = 1;
	bool is;
	
	do{
		day++;
		day%=delta;
		is = false;
		memset(tbacs,0,sizeof tbacs);
		// who to add?
		fori(i,1,n+1){
			fori(j,1,n+1){
				if(bacs[i][j] > 0 && !issat[i][j]){
					addbac(i-1,j);
					addbac(i,j-1);
					addbac(i+1,j);
					addbac(i,j+1);
				}
			}
		}
		// apply addition
		fori(i,1,n+1){
			fori(j,1,n+1){
				if(tbacs[i][j] && !issat[i][j]){
					bacs[i][j] += tbacs[i][j];
					is = true;
				}
			}
		}
		// saturation
		fori(i,1,n+1){
			fori(j,1,n+1){
				if(bacs[i][j] >= getcap(i,j)){
					bacs[i][j] = 0;
					sattime[i][j] = day;
					issat[i][j] = 1;
				}
			}
		}
	}while(is);
	
	fori(i,1,n+1){
		fori(j,1,n+1){
			ans += sattime[i][j];
			ans %= delta;
		}
	}
	
	cout << ppow(ans,3,true,delta) << endl;
}

