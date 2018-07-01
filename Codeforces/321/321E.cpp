//In The Name of Allah
//Tue 6/4/97
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
	//Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	//cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

int n,k;
int pdt[4001][4001],dp[801][4001];
char c;

inline int getcost(int b,int e){
	if(b>0)
		return (pdt[e][e]-pdt[b-1][e]-pdt[e][b-1]+pdt[b-1][b-1])/2;
	else
		return pdt[e][e]/2;
}

void solve(int curk,int curb,int cure,int prevb,int preve){
	if(cure < curb || !cure)
		return;
	if(cure - curb + 1 <= 2){
		dp[curk][cure] = dp[curk][curb] = mod;
		int mt = max(min(curb,preve+1),min(cure,preve+1));
		fori(i,prevb,mt){
			if(i < min(curb,preve+1))
				dp[curk][curb] = min(dp[curk][curb],dp[curk-1][i] + getcost(i+1,curb));
			if(i < min(cure,preve+1))
				dp[curk][cure] = min(dp[curk][cure],dp[curk-1][i] + getcost(i+1,cure));
		}
		return;
	}
	int mid = (cure+curb)/2;
	int pt = prevb;
	dp[curk][mid] = dp[curk-1][prevb] + getcost(prevb+1,mid);
	fori(i,prevb,min(preve+1,mid)){
		if(dp[curk][mid] > dp[curk-1][i] + getcost(i+1,mid)){
			pt = i;
			dp[curk][mid] = dp[curk-1][i] + getcost(i+1,mid);
		}
	}
	solve(curk,curb,mid-1,prevb,pt);
	solve(curk,mid+1,cure,pt,preve);
}

inline void Solution(){
	scanf("%d%d",&n,&k);
	forar(i,n){
		forar(j,n){
			while((c = getchar()) < '0' || c > '9');
			pdt[i][j] = c-'0';
			pdt[i][j] += (j>0 ? pdt[i][j-1] : 0);
			pdt[i][j] += (i>0 ? pdt[i-1][j] : 0);
			pdt[i][j] -= (i>0 && j>0 ? pdt[i-1][j-1] : 0);
		}
	}
	forar(i,n){
		dp[1][i] = getcost(0,i);
	}
	fori(tk,2,k+1){
		solve(tk,0,n-1,0,n-1);
	}
	printf("%d\n", dp[k][n-1]);
}
