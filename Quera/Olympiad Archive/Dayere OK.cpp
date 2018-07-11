//In The Name of Allah
//Mon 18/4/97
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

const ll mod = 1e9+7,M = 500;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

int n,ans;
struct circle
{
	ll x,y,r;
	bool operator<(circle b){
		return r<b.r;
	}
} circs[M];
bool ign[M];

bool isInscribed(int _a,int _b){
	auto& a = circs[_a];
	auto& b = circs[_b];
	ll odist = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
	ll dif = (a.r-b.r)*(a.r-b.r);
	return dif>odist;
}

inline void Solution(){
	cin >> n;
	forar(i,n){
		cin >> circs[i].x >> circs[i].y >> circs[i].r;
	}
	sort(circs,circs+n);
	// ignore singles
	forar(t,n){
		forar(i,n){
			int cn = 0,ind = -1;
			forar(j,i){
				if(ign[j])
					continue;
				if(isInscribed(i,j)){
					++cn;
					ind = j;
				}
			}
			if(cn == 1)
				ign[ind] = 1;
		}
	}
	// lets go!
	forar(i,n){
		if(ign[i])
			continue;
		int cn = 0,ind = -1;
		forar(j,i){
			if(ign[j])
				continue;
			if(isInscribed(i,j)){
				++cn;
				ind = j;
			}
		}
		if(cn)
			ign[ind] = 1;
		else
			++ans;
	}
	cout << ans << endl;
}
