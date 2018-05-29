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

int mark[10000];

inline void Solution(){
	int mx = 0,ind = 0;
	fori(i,2,1000){
		memset(mark,0,sizeof mark);
		int nom = 1,res=0;
		for(int k = 1;k <= 10000;k++){
			if(nom == 0)
				break;
			if(mark[nom]){
				res = k - mark[nom];
				break;
			}
			mark[nom] = k;
			nom *= 10;
			nom %= i;
		}
		if(res > mx){
			mx = res;
			ind = i;
		}
	}
	cout << ind << endl;
}
