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
Data data[1000];
int n,ans;
int cows[3];

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
	cin >> n;
	forar(i,n){
		cin >> data[i].day;
		string s;
		cin >> s;
		if(s == "Bessie"){
			data[i].cow = 0;
		}else if(s == "Elsie"){
			data[i].cow = 1;
		}else{
			data[i].cow = 2;
		}
		cin >> data[i].change;
	}
	sort(data,data+n,comp);
	forar(i,n){
		int mx = *max_element(cows,cows+3);
		bool p[6] = {0,0,0,0,0,0};
		forar(i,3){
			if(cows[i] == mx)
				p[i]=1;
		}
		cows[data[i].cow] += data[i].change;
		mx = *max_element(cows,cows+3);
		forar(i,3){
			if(cows[i] == mx)
				p[i+3]=1;
		}
		bool is = false;
		forar(i,3){
			if(p[i] != p[i+3])
				is = true;
		}
		if(is)
			ans++;
	}
	cout << ans << endl;
}
