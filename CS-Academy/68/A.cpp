//In The Name of Allah
//Wed 18/11/96
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

int main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	int n;
	cin >> n;
	vector<string> slist;
	forar(i,n){
		string a;
		cin >> a;
		slist.pb(a);
	}
	set<int> ans;
	forar(k,n){
		forar(i,n){
			fori(j,i+1,n){
				string r1 = slist[i]+slist[j];
				string r2 = slist[j]+slist[i];
				if(slist[k] == r1 || slist[k] == r2)
					ans.insert(k+1);
			}
		}
	}
	for(int x : ans){
		cout << x << " ";
	}
}
