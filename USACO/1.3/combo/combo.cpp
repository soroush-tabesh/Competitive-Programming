/*
ID: soroosh4
LANG: C++11
TASK: combo
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("combo.in","r",stdin),freopen("combo.out","w",stdout)
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

set<int> used[3][3];
int n,ans1,ans2,ans3;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(k,2){
		forar(i,3){
			int a;
			cin >> a;
			a--;
			a = (a+n-2)%n;
			forar(j,5){
				used[i][k].insert((a+j)%n);
				used[i][2].insert((a+j)%n);
			}
		}
	}
	ans1 = ans2 = ans3 = 1;
	forar(i,3){
		ans1 *= used[i][0].size();
	}
	forar(i,3){
		ans2 *= used[i][1].size();
	}
	forar(i,3){
		ans3 *= used[i][0].size() + used[i][1].size() - used[i][2].size();
	}
	
	cout << ans1 + ans2 - ans3 << '\n';
}
