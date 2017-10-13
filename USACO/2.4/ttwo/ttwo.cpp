/*
ID: soroosh4
LANG: C++11
TASK: ttwo
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("ttwo.in","r",stdin),freopen("ttwo.out","w",stdout)
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

pii walk[4] = {{-1,0},{0,1},{1,0},{0,-1}}; // N E S W

bool obs[101][101];
int n=10,w=10;
pii fj;
int fjv;
pii cow;
int cowv;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	forar(i,n){
		forar(j,w){
			char c;
			cin >> c;
			if(c=='*'){
				obs[i][j] = 1;
			}else if(c=='F'){
				fj = {i,j};
			}else if(c=='C'){
				cow = {i,j};
			}
		}
	}
	int i = 0;
	bool is = false;
	// start sim
	while(i<9000 && !is){
		// walk fj
		if(obs[fj.F + walk[fjv].F][fj.S + walk[fjv].S] || fj.F + walk[fjv].F >= n || fj.S + walk[fjv].S >= w || fj.F + walk[fjv].F < 0 || fj.S + walk[fjv].S < 0){
			fjv++;
			fjv %= 4;
		}else{
			fj.F += walk[fjv].F;
			fj.S += walk[fjv].S;
		}
		
		// walk cows
		if(obs[cow.F + walk[cowv].F][cow.S + walk[cowv].S] || cow.F + walk[cowv].F >= n || cow.S + walk[cowv].S >= w || cow.F + walk[cowv].F < 0 || cow.S + walk[cowv].S < 0){
			cowv++;
			cowv %= 4;
		}else{
			cow.F += walk[cowv].F;
			cow.S += walk[cowv].S;
		}
		
		// check collision
		is = cow == fj;
		
		//end
		i++;
	}
	if(is){
		cout << i << endl;
	}else{
		cout << 0 << endl;
	}
}
