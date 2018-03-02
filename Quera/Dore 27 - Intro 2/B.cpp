//In The Name of Allah
//Fri 12/12/96
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

int n,mx;
struct Ghoul{
	int id,pwr,health,cost;
}
Ghoul gh[2100];
//int dp

int main()
{
	Init;
	Solution();
	return 0;
}

bool solve(int money){
	mx = 0;
}

bool cmp(Ghoul& a,Ghoul& b){
	return a.pwr > b.pwr;
}

inline void Solution(){
	cin >> n;
	forar(i,n){
		gh[i].id = i;
		cin >> gh[i].pwr >> gh[i].health >> gh[i].cost;
	}
	sort(gh,gh+n,cmp);
	int l = 0,r = 5*1000*1000;
	while(r != l){
		int mid = (r+l)/2;
		if(solve(mid)){
			r=mid-1;
		}else{
			l = mid;
		}
	}
	cout << mid + 1 << endl;
}
