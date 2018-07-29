//In The Name of Allah
//Sun 7/5/97
#pragma GCC optimize "-Ofast"
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
#define fori(i,a,b) for(int i = a; i < b;++i)
#define forar(i,n) fori(i,0,n)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LSB(x) (x&(-x))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

int n,m,x;
int*** dp;

inline void madd(int &a,ll b){
	a = (1LL * a + b)%mod;
}

ll fac(ll x){
	return x ? (x*fac(x-1))%mod : 1;
}

inline void Solution(){
	cin >> n >> m >> x;
	if(n > m){
		cout << 0 << endl;
		return;
	}
	dp = new int**[m+1];
	forar(i,m+1){
		dp[i] = new int*[n+2];
		forar(j,n+2){
			dp[i][j] = new int[n+2];
			forar(k,n+2){
				dp[i][j][k] = 0;
			}
		}
	}
	dp[0][0][0] = 1;
	forar(i,m){
		forar(j,min(n,i)+1){
			forar(k,min(n,m-i)+1){
				madd(dp[i+1][j][k+1],dp[i][j][k]); // open
				madd(dp[i+1][j+1][k],dp[i][j][k]); // open and close
				if(x != i+1){
					madd(dp[i+1][j][k],dp[i][j][k]); // non
					if(k)
						madd(dp[i+1][j+1][k-1],dp[i][j][k]); // close
				}
			}
		}
	}
	cout << (dp[m][n][0] * fac(n))%mod << endl;
}
