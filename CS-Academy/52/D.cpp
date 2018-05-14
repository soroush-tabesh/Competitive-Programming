//In The Name of Allah
//Wed 19/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+5;

void Solution();

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	int t;
	int ans;
	cin >> t;
	while(t--){
		int base = 17;
		cout << base << flush;
		cin >> ans;
		if(ans){
			cout << (base+11)%100 << flush;
			cin >> ans;
			if(ans){
				fori(i,22,30){
					cout << (i+base)%100 << flush;
					cin >> ans;
				}
				cout << (base+32)%100 << flush;
			}else{
				int pr = (base+11)%100;
				int mv = 2;
				while(mv < 11){
					pr = (pr+10)%100;
					mv++;
					cout << pr << flush;
					cin >> ans;
				}
			}
		}else{
			int mv = 1;
			int pr2;
			int pr1 = base;
			while(mv < 11){
				mv++;
				pr1=(pr1+10)%100;
				cout << pr1 << flush;
				cin >> ans;
				if(ans){
					
				}
			}
			
		}
	}
}

