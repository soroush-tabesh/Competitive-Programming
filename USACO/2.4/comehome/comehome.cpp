/*
ID: soroosh4
LANG: C++11
TASK: comehome
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("comehome.in","r",stdin),freopen("comehome.out","w",stdout)
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

int n;
int dist[125][125];
const int inf = 1000*1000;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	fori(i,60,124)
		fori(j,60,124)
			if(i != j)
				dist[i][j] = inf;
	forar(i,n){
		char a,b;
		int d;
		cin >> a >> b >> d;
		if(a == b)
			continue;
		dist[int(a)][int(b)] = min(d,dist[int(a)][int(b)]);
		dist[int(b)][int(a)] = min(d,dist[int(b)][int(a)]);
	}
	fori(k,60,124)
		fori(i,60,124)
			fori(j,60,124)
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	int minptr = -1;
	int mind = inf;
	fori(i,60,124){
		if(i == int('Z') || islower(i))
			continue;
		if(dist[i][int('Z')] < mind){
			mind = dist[i][int('Z')];
			minptr = i;
		}
	}
	cout << char(minptr) << " " << mind << endl;
}
