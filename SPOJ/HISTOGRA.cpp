//In The Name of Allah
//Fri 21/7/96
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

const ll mod = 1e9+7,M = 2e5+5;

void Solution();

ll data[M];
int dpL[M];
int dpR[M];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void Solution(){
	int n;
	cin >> n;
	while(n){
		forar(i,n){
			cin >> data[i];
		}
		stack<int> cand;
		forar(i,n){
			while(!cand.empty() && data[cand.top()] >= data[i]){
				cand.pop();
			}
			if(cand.empty()){
				dpL[i] = -1;
			}else{
				dpL[i] = cand.top();
			}
			cand.push(i);
		}
		while(!cand.empty())
			cand.pop();
		forar(k,n){
			int i = n-k-1;
			while(!cand.empty() && data[cand.top()] >= data[i]){
				cand.pop();
			}
			if(cand.empty()){
				dpR[i] = n;
			}else{
				dpR[i] = cand.top();
			}
			cand.push(i);
		}
		ll ans = 0;
		forar(i,n){
			ans = max(ans,(dpR[i]-dpL[i]-1)*data[i]);
		}
		cout << ans << endl;
		cin >> n;
	}
}
