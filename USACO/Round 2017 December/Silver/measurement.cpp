//In The Name of Allah
//Sat 25/9/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("measurement.in","r",stdin),freopen("measurement.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define clamp(a,b,i) max(min(i,b),a)
#define infint 1000*1000*1000

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

struct Data{
	int day,cow,change;
};
Data data[M];
int n,ans,cowcnt,g;
int milk[M];
map<int,int> cowmap;
map<int,int,greater<int> > stat;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

bool comp(Data a,Data b){
	return a.day < b.day;
}

void Solution(){
	cin >> n >> g;
	forar(i,n){
		cin >> data[i].day >> data[i].cow >> data[i].change;
		if(!cowmap[data[i].cow]){
			cowmap[data[i].cow] = ++cowcnt;
		}
		data[i].cow = cowmap[data[i].cow];
	}
	stat[0] = n+5;
	sort(data,data+n,comp);
	forar(i,n){
		if(milk[data[i].cow] == stat.begin()->F){
			if(stat.begin()->S > 1){
				ans++;
			}else if(milk[data[i].cow]+data[i].change <= next(stat.begin())->F ){
				ans++;
			}
		}else if(milk[data[i].cow]+data[i].change >= stat.begin()->F ){
			ans++;
		}
		stat[milk[data[i].cow]]--;
		if(stat[milk[data[i].cow]]==0)
			stat.erase(milk[data[i].cow]);
		milk[data[i].cow] += data[i].change;
		stat[milk[data[i].cow]]++;
	}
	cout << ans << endl;
}
