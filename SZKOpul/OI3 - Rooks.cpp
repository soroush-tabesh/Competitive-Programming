//In The Name of Allah
//Tue 16/4/97
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

int n;
struct rect
{
	int lui,luj,rdi,rdj,id;
} rects[5001];
struct point
{
	int i,j;
} ans[5001];
bool markud[5000],marklr[5000];

inline void Solution(){
	cin >> n;
	forar(i,n){
		cin >> rects[i].lui >> rects[i].luj >> rects[i].rdi >> rects[i].rdj;
		rects[i].id = i;
	}
	fori(pi,1,n+1){
		int ind = -1;
		forar(t,n){
			if(markud[t] || pi < rects[t].lui || pi > rects[t].rdi)
				continue;
			if(ind == -1)
				ind = t;
			else if(rects[t].rdi < rects[ind].rdi)
				ind = t;
		}
		if(ind == -1){
			cout << "NIE" << endl;
			return;
		}
		markud[ind] = 1;
		ans[ind].i = pi;
	}
	fori(pj,1,n+1){
		int ind = -1;
		forar(t,n){
			if(marklr[t] || pj < rects[t].luj || pj > rects[t].rdj)
				continue;
			if(ind == -1)
				ind = t;
			else if(rects[t].rdj < rects[ind].rdj)
				ind = t;
		}
		if(ind == -1){
			cout << "NIE" << endl;
			return;
		}
		marklr[ind] = 1;
		ans[ind].j = pj;
	}
	forar(_i,n){
		cout << ans[_i].i << " " << ans[_i].j << endl;
	}
}
