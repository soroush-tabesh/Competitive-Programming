//In The Name of Allah
//Tue 5/4/97
#pragma GCC optimize "-Ofast"
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
#define fori(i,a,b) for(ll i = a; i < b;i++)
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

inline void decom(int* arr,int x){
	while(x){
		++arr[x%10];
		x/=10;
	}
}

inline void Solution(){
	int c = 0;
	int cn1[10];
	int cn2[10];
	ll nom = 1,den = 1;
	fori(i,10,100){
		fori(j,i+1,100){
			memset(cn1,0,sizeof cn1);
			memset(cn2,0,sizeof cn2);
			decom(cn1,i);
			decom(cn2,j);
			bool is = false;
			forar(d,10){
				if(cn1[d] && cn2[d]){
					is = true;
					--cn1[d];
					--cn2[d];
				}
			}
			if(!is || (i%10 == 0 && j%10 == 0))
				continue;
			int a,b;
			forar(d,10){
				if(cn1[d])
					a = d;
				if(cn2[d])
					b = d;
			}
			if(b*i == a*j){
				nom*=a;
				den*=b;
				++c;
				cout << i << "/" << j << " , " << a << "/" << b << endl;
			}
		}
	}
	den /= __gcd(nom,den);
	cout << den << endl;
	Log(c);
}
