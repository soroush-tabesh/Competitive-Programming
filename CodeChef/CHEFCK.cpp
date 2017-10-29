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

const ll mod = 1e9+7,M = 1e7+100;

void Solution();

ll n,k,q;
ll a,b,c,d,e,f,r,s,t,m;
ll data[M];
ll L1,La,Lc,Lm,D1,Da,Dc,Dm;
ll sum,prod=1;
deque<ll> cands;
ll ans[M];

int main()
{
	Init;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> k >> q;
	cin >> a >> b >> c >> d >> e >> f >> r >> s >> t >> m >> data[0];
	cin >> L1 >> La >> Lc >> Lm >> D1 >> Da >> Dc >> Dm;
	ll tp = t;
	fori(i,1,n){
		tp *= t;
		tp %= s;
		if(tp <= r)
			data[i] = (((a*((data[i-1]*data[i-1])%m))%m) + ((b*data[i-1])%m) + c)%m;
		else
			data[i] = (((d*((data[i-1]*data[i-1])%m))%m) + ((e*data[i-1])%m) + f)%m;
	}
	forar(i,n){
		if(i >= k && i-k == cands.back()){
			cands.pop_back();
		}
		while(!cands.empty() && data[cands.front()] >= data[i]){
			cands.pop_front();
		}
		cands.push_front(i);
		if(i>=k-1){
			ans[i-k+1] = data[cands.back()];
		}
	}
	forar(i,q){
		L1 = (La * L1 + Lc) % Lm;
		D1 = (Da * D1 + Dc) % Dm; 
		int L = L1 + 1;
		int R = min(L + k - 1 + D1, n);
		L--;
		R--;
		ll res = min(ans[L],ans[R-k+1]);
		sum += res;
		prod *= res;
		prod %= mod;
	}
	cout << sum << " " << prod << endl;
}
