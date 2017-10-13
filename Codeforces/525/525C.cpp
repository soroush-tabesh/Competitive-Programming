//In The Name of Allah
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
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

void Solution();

ll n;
map<int,pii,greater<int> > len2cnt;
vector<pii> data;
ll ans;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		ll a;
		cin >> a;
		len2cnt[a].F++;
	}
	
	for(map<int,pii,greater<int> >::iterator it = len2cnt.begin();it != len2cnt.end();it++){
		if((it->S.F + it->S.S)%2==1 && it->S.F > 0){
			it->S.F--;
			len2cnt[it->F -1].S++;
		}
	}
	
	for(pair<int,pii> p : len2cnt){
		if(p.S.S + p.S.F <= 1)
			continue;
		data.pb({p.F,p.S.F+p.S.S});
	}
	
	forar(i,data.size()){
		while(data[i].S >= 4){
			data[i].S -= 4;
			ans += 1LL * data[i].F * data[i].F;
		}
		if(data[i].S >= 2){
			fori(j,i+1,data.size()){
				if(data[j].S >= 2){
					data[j].S -= 2;
					data[i].S -= 2;
					ans += 1LL * data[i].F * data[j].F;
					break;
				}
			}
		}
	}
	cout << ans << endl;
	
}

