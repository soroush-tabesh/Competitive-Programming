//In The Name of Allah
//Mon 3/7/96
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

const ll mod = 1e9+7,M = 1e2+5;

void Solution();

ll ep,cap,petst,jour,fuel,ans;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> ep >> cap >> petst >> jour;
	fuel = cap;
	int ps = 1;
	while(jour > 0){
		if(fuel < (ps ? petst : (ep-petst)) || cap < (ps ? (ep-petst) : petst) || fuel < 0){
			cout << -1;
			return;
		}
		if(fuel >= 2*ep){
			fuel -= ep;
		}else if(jour > 1){
			if(fuel < ep+(ps ? ep-petst:petst)){
				fuel = cap - (ps ? ep-petst : petst);
				ans++;
			}else{
				fuel -= ep;
			}
		}else{
			if(fuel < ep){
				ans++;
			}
		}
		jour--;
		ps++;
		ps%=2;
	}
	cout << ans;
}
