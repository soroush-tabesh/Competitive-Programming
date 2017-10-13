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

ll n,k;
ll data[200];

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
	cin >> n >> k;
	
	ll n4 = n;
	ll n2 = 2*n;
	ll n21 = 0;
	bool is = true;
	
	forar(i,k){
		cin >> data[i];
		
		ll t2 = data[i]/2; // pair seats
		ll t21 = data[i] - 2*t2; // single pair seats
		
		if(n4 > 0 && t2 > 0){
			ll need = t2/2;
			need = min(need,n4);
			t2 -= 2*need;
			n4 -= need;
		}
		if(n2 > 0 && t2 > 0){
			ll need = t2;
			need = min(need,n2);
			t2-=need;
			n2-=need;
		}
		if(n4 > 0 && t2 > 0){
			n4--;
			n21++;
			t2--;
		}
		
		t21 += t2*2;
		t2 = 0;
		
		while(n21 > 0 && t21 > 0){
			n21--;
			t21--;
		}
		while(n4 > 0 && t21 > 0){
			n4--;
			n2++;
			t21--;
		}
		while(n2 > 0 && t21 > 0){
			n2--;
			t21--;
		}
		
		if(t2 > 0 || t21 > 0){
			is = false;
		}
	}
	
	if(is)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
}