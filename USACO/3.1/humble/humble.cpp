//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: humble
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("humble.in","r",stdin),freopen("humble.out","w",stdout)
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

int n,k,scnt;
ll primes[105];
typedef pair<ll,short> pls;
vector<pls> infim; ll hmax = 1;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

bool comp(pls a,pls b){
	return a > b;
}

void Solution(){
	cin >> k >> n;
	forar(i,k){
		cin >> primes[i];
	}
	sort(primes,primes+k);
	infim.pb({1,0});
	while(scnt < n){
		pls topro = infim.front();
		
		pop_heap(infim.begin(),infim.end(),comp);
		infim.pop_back();
		
		scnt++;
		fori(i,topro.S,k){
			ll toadd = primes[i]*topro.F;
			if(!(toadd > hmax && infim.size() > 100*1000) && (toadd/4 < 1000*1000*1000)){
				infim.pb({toadd,i});
				hmax = max(toadd,hmax);
				push_heap(infim.begin(),infim.end(),comp);
			}
		}
		
	}
	cout << infim.front().F << endl;
}
