/*
ID: soroosh4
LANG: C++11
TASK: skidesign
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("skidesign.in","r",stdin),freopen("skidesign.out","w",stdout)
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

int n;
int hills[1000+5];
int change[1000+5];
int cost;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> hills[i];
	}
	sort(hills,hills+n);
	while(hills[n-1] - hills[0] > 17){
		int dcosthi = 0,dcostlow = 0;
		// Let's do the greedy job!
		// what if we change the biggests ?
		int cnthi = n-1;
		while(cnthi > 0 && hills[cnthi-1] == hills[n-1])
			cnthi--;
		cnthi = n - cnthi;
		forar(i,cnthi){
			dcosthi += (change[n-i-1]+1)*(change[n-i-1]+1) - (change[n-i-1])*(change[n-i-1]);
		}
		
		// what if we change the smallests ?
		int cntlow = 0;
		while(cntlow < n-1 && hills[cntlow+1] == hills[0])
			cntlow++;
		cntlow++;
		forar(i,cntlow){
			dcostlow += (change[i]+1)*(change[i]+1) - (change[i])*(change[i]);
		}
		
		// decide and make the change
		if(dcostlow <= dcosthi){
			forar(i,cntlow){
				change[i]++;
				hills[i]++;
			}
			cost += dcostlow;
		}else{
			forar(i,cnthi){
				change[n-i-1]++;
				hills[n-i-1]--;
			}
			cost += dcosthi;
		}
	}
	
	cout << cost << endl;
}
