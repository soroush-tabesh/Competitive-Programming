//In The Name of Allah
//Fri 26/8/96
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

int n;
int data[M][20];

int main()
{
	Init;
	Solution();
	return 0;
}

int get(int i,int j){
	int res = 0;
	for(int k = 15;k >= 0;k--){
		if((1<<k) <= j-i){
			res = __gcd(data[i][k],res);
			i += 1<<k;
		}
	}
	return res;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i][0];
	}
	fori(j,1,15){
		forar(i,n){
			data[i][j] = __gcd(data[i][j-1],data[i+(1<<(j-1))][j-1]);
		}
	}
	ll mn = n+2;
	forar(i,n){
		fori(j,i,n){
			if(get(i,j+1) == 1){
				mn = min(mn,j-i);
			}
		}
	}
	if(mn == n+2)
		cout << -1 << endl;
	else
		cout << mn-1+n-1 << endl;
}
