/*
ID: soroosh4
LANG: C++11
TASK: friday
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("friday.in","r",stdin),freopen("friday.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;
const int M = 100*1000+5;

void Solution();

int days[7];
int n;
int y=1900,m=1,d=1,week=3;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	while(y < n + 1900){
		if(d==13)
			days[week-1]++;
		week++;
		d++;
		if(week > 7) week = 1;
		switch(m){
			case 1:
				if(d > 31){
					d=1;
					m++;
				}
				break;
			case 2:
				if(y%100 != 0 && y % 4 == 0 || y%400 == 0){
					if(d>29){
						d=1;
						m++;
					}
				}else{
					if(d>28){
						d=1;
						m++;
					}
				}
				break;
			case 3:
				if(d > 31){
					d=1;
					m++;
				}
				break;
			case 4:
				if(d > 30){
					d=1;
					m++;
				}
				break;
			case 5:
				if(d > 31){
					d=1;
					m++;
				}
				break;
			case 6:
				if(d > 30){
					d=1;
					m++;
				}
				break;
			case 7:
				if(d > 31){
					d=1;
					m++;
				}
				break;
			case 8:
				if(d > 31){
					d=1;
					m++;
				}
				break;
			case 9:
				if(d > 30){
					d=1;
					m++;
				}
				break;
			case 10:
				if(d > 31){
					d=1;
					m++;
				}
				break;
			case 11:
				if(d > 30){
					d=1;
					m++;
				}
				break;
			case 12:
				if(d > 31){
					d=1;
					m=1;
					y++;
				}
				break;
		}
	}
	forar(i,7){
		cout << days[i];
		if(i!=6)
			cout << " ";
	}
	cout << "\n";
}
