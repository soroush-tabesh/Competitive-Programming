//In The Name of Allah
//Sun 9/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e5+5;

void Solution();

int w,h;
int ans;
bool data[20][20];
int cnt;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void solve(int mh,int mw){
	if(mh == 0){
		bool is = true;
		fori(i,1,h+1){
			fori(j,1,w+1){
				is &= !(data[i][j] && data[i][j+1]);
				is &= !(data[i][j] && data[i][j-1]);
				is &= !(data[i][j] && data[i+1][j]);
				is &= !(data[i][j] && data[i-1][j]);
			}
		}
		if(is)
			ans++;
	}else if(mw == 0){
		solve(mh-1,w);
	}else{
		solve(mh,mw-1);
		data[mh][mw] = 1;
		solve(mh,mw-1);
		data[mh][mw] = 0;
	}
}

void Solution(){
	cin >> h >> w;
	solve(h,w);
	cout << ans << endl;
}
