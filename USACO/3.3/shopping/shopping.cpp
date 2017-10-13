//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: shopping
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("shopping.in","r",stdin),freopen("shopping.out","w",stdout)
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

int dp[6][6][6][6][6];
int purch[10];
int prices[10];
int cnt,s,p;
map<int,int> ids;
struct Offer{
	int amount[5];
	int price;
};
typedef struct Offer Offer;
Offer offers[100];
const int inf = 1e9;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

int getid(int id){
	if(!ids[id]){
		cnt++;
		ids[id] = cnt;
	}
	return ids[id]-1;
}

int solve(int a1,int a2,int a3,int a4,int a5){
	if(dp[a1][a2][a3][a4][a5] != -1){
		return dp[a1][a2][a3][a4][a5];
	}
	dp[a1][a2][a3][a4][a5] = inf;
	forar(i,s){
		if(a1-offers[i].amount[0] >= 0 && a2-offers[i].amount[1] >= 0 && a3-offers[i].amount[2] >= 0 && a4-offers[i].amount[3] >= 0 && a5-offers[i].amount[4] >= 0){
			int ndndn = solve(a1-offers[i].amount[0],a2-offers[i].amount[1],a3-offers[i].amount[2],a4-offers[i].amount[3],a5-offers[i].amount[4])+offers[i].price;
			dp[a1][a2][a3][a4][a5] = min(dp[a1][a2][a3][a4][a5]
			,solve(a1-offers[i].amount[0],a2-offers[i].amount[1],a3-offers[i].amount[2],a4-offers[i].amount[3],a5-offers[i].amount[4])+offers[i].price);
		}
	}
	if(a1)
		dp[a1][a2][a3][a4][a5] = min(dp[a1][a2][a3][a4][a5],solve(a1-1,a2,a3,a4,a5)+prices[0]);
	if(a2)
		dp[a1][a2][a3][a4][a5] = min(dp[a1][a2][a3][a4][a5],solve(a1,a2-1,a3,a4,a5)+prices[1]);
	if(a3)
		dp[a1][a2][a3][a4][a5] = min(dp[a1][a2][a3][a4][a5],solve(a1,a2,a3-1,a4,a5)+prices[2]);
	if(a4)
		dp[a1][a2][a3][a4][a5] = min(dp[a1][a2][a3][a4][a5],solve(a1,a2,a3,a4-1,a5)+prices[3]);
	if(a5)
		dp[a1][a2][a3][a4][a5] = min(dp[a1][a2][a3][a4][a5],solve(a1,a2,a3,a4,a5-1)+prices[4]);
    return dp[a1][a2][a3][a4][a5];
}

void Solution(){
	cin >> s;
	forar(i,s){
		int a;
		cin >> a;
		forar(j,a){
			int c,m;
			cin >> c >> m;
			offers[i].amount[getid(c)] = m;
		}
		cin >> offers[i].price;
	}
	cin >> p;
	forar(i,p){
		int id;
		cin >> id;
		id = getid(id);
		cin >> purch[id] >> prices[id];
	}
	forar(a1,6){
		forar(a2,6){
			forar(a3,6){
				forar(a4,6){
					forar(a5,6){
						dp[a1][a2][a3][a4][a5] = -1;
					}
				}
			}
		}
	}
	dp[0][0][0][0][0] = 0;
	cout << solve(purch[0],purch[1],purch[2],purch[3],purch[4]) << endl;
}
