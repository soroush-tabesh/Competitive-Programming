//In The Name of Allah
//Tue 18/2/97
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	int n,k;
	cin >> n >> k;
	cout << "YES" << endl;
	if(k%2){
		forar(i,n){
			cout << '.';
		}
		cout << endl;
		
		if(k>n-2){
			cout << '.';
			forar(i,n-2){
				cout << '#';
			}
			cout << '.';
			cout << endl;
			cout << '.';
			forar(i,(k-n+2)/2){
				cout << '#';
			}
			forar(i,n-(k-n+2)-2){
				cout << '.';
			}
			forar(i,(k-n+2)/2){
				cout << '#';
			}
			cout << '.';
		}else{
			forar(i,(n-k)/2){
				cout << '.';
			}
			forar(i,k){
				cout << '#';
			}
			forar(i,(n-k)/2){
				cout << '.';
			}
			cout << endl;
			forar(i,n){
				cout << '.';
			}
		}
		
		cout << endl;
		forar(i,n){
			cout << '.';
		}
		cout << endl;
	}else{
		forar(i,n){
			cout << '.';
		}
		cout << endl;
		cout << '.';
		forar(i,k/2){
			cout << '#';
		}
		forar(i,n-k/2-1){
			cout << '.';
		}
		cout << endl;
		cout << '.';
		forar(i,k/2){
			cout << '#';
		}
		forar(i,n-k/2-1){
			cout << '.';
		}
		cout << endl;
		
		forar(i,n){
			cout << '.';
		}
		cout << endl;
	}
}
