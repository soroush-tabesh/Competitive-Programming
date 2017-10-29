//In The Name of Allah
//Sat 6/8/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(int i = a; i < b;i++)
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

int n,t,data[M],ans[M],nxt[M],prv[M];
stack<int> cands;

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> t;
	while(t--){
		cin >> n;
		forar(i,n){
			cin >> data[i];
		}
		fill(ans,ans+n+1,0);
		while(!cands.empty())
				cands.pop();
		forar(i,n){
			while(!cands.empty() && data[cands.top()] >= data[i])
				cands.pop();
			if(!cands.empty())
				prv[i] = cands.top();
			else
				prv[i] = -1;
			cands.push(i);
		}
		while(!cands.empty())
				cands.pop();
		forar(i,n){
			while(!cands.empty() && data[cands.top()] >= data[n-i-1])
				cands.pop();
			if(!cands.empty())
				nxt[n-i-1] = cands.top();
			else
				nxt[n-i-1] = -1;
			cands.push(n-i-1);
		}
		forar(i,n){
			int dl = (prv[i] == -1) ? (i) : (i - prv[i] - 1);
			int dr = (nxt[i] == -1) ? (n-i-1) : (nxt[i] - i - 1);
			int sz = dr+dl+1;
			ans[sz] = max(ans[sz],data[i]);
		}
		forar(i,n){
			ans[n-i-1] = max(ans[n-i-1],ans[n-i]);
		}
		forar(i,n){
			cout << ans[i+1] << " ";
		}
		cout << endl;
	}
}
