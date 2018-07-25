//In The Name of Allah
//Wed 3/5/97
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

ll n,a[M],b[M],c[M],t[M],cnt[64];

inline void Solution(){
	cin >> n;
	forar(i,n){
		cin >> b[i];
		t[i] += b[i];
	}
	ll sgt = 0;
	bool is = true;
	forar(i,n){
		cin >> c[i];
		t[i] += c[i];
		sgt += t[i];
		if(i)
			is &= t[i]%n == t[i-1]%n;
	}
	if(!is){
		cout << -1 << endl;
		return;
	}
	ll sum = sgt/(2*n);
	forar(i,n){
		a[i] = (t[i]-sum)/n;
		ll j = 0,tmp = a[i];
		while(tmp){
			cnt[j++] += (tmp & 1);
			tmp >>= 1;
		}
	}
	forar(i,n){
		ll bp = 0,cp = 0;
		ll tmp = a[i];
		forar(j,40){
			if(tmp&1){
				bp += (1LL<<j)*cnt[j];
				cp += (1LL<<j)*n;
			}else{
				cp += (1LL<<j)*cnt[j];
			}
			tmp >>= 1;
		}
		is &= bp == b[i] && cp == c[i];
	}
	if(is){
		forar(i,n){
			cout << a[i] << " ";
		}
	}else{
		cout << -1 << endl;
	}
}
