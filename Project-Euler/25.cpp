//In The Name of Allah
//Thu 27/2/97
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

int num[10000][1100];

inline void Solution(){
	// Solution 1:
	cout << ceil((999.0+log10(sqrt(5)))/log10((sqrt(5)+1)/2)) << endl;
	// Solution 2:
	num[2][0] = num[1][0] = 1;
	fori(i,2,10000){
		ll carry = 0;
		forar(j,1100){
			carry += num[i-1][j] + num[i-2][j];
			num[i][j] = carry%10;
			carry /= 10;
		}
		int cnt = 1100;
		while(num[i][cnt-1]==0){
			--cnt;
		}
		if(cnt >= 1000){
			cout << i << endl;
			break;
		}
	}
}
