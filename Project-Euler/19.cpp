//In The Name of Allah
//Wed 26/2/97
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

int weekday = 2; // 0-based
int day = 1; // 1-based
int month = 1; // 1-base
int year = 1900;
int ans = 0;

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline int getmonlen(){
	if(month == 2){
		return 28 + int((year%4==0&&year%100!=0)||year%400==0);
	}
	if(month ==  11 || month == 9 || month == 4 || month == 6)
		return 30;
	return 31;
}

inline void Solution(){
	while(!(day == 31 && month == 12 && year == 2000)){
		if(day == 1 && weekday == 1 && year >= 1901)
			ans++;
		++day;
		if(day > getmonlen()){
			++month;
			day = 1;
		}
		if(month > 12){
			++year;
			month = 1;
		}
		weekday = (weekday+1)%7;
	}
	cout << ans << endl;
}
