//In The Name of Allah
//Mon 24/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e5+5;

void Solution();

bool data[M];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	int n;
	cin >> n;
	while(n){
		forar(i,n){
			char c;
			cin >> c;
			data[i] = (c=='x');
		}
		int ans = 0;
		bool is = true;
		while(is){
			is = false;
			ans++;
			forar(i,n-1){
				if(data[i] && !data[i+1]){
					swap(data[i],data[i+1]);
					is = true;
				}
			}
			forar(i,n){
				cout << (data[i] ? 'x': 'o');
			}
			cout << endl;
		}
		cout << ans << endl;
		cin >> n;
	}
}
