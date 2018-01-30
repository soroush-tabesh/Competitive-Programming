//In The Name of Allah
//Mon 9/11/96
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

int n,m;
vector<pair<int,int> > adjout[200];
int state[30][200][200]; // 0:N/A 1:W 2:L

int main()
{
	Init;
	Solution();
	return 0;
}

int getdp(int va,int vb,int tme){
	if(state[tme][va][vb])
		return state[tme][va][vb];
	bool ans = 0;
	for(auto neib : adjout[va]){
		if(neib.S < tme)
			continue;
		ans |= (getdp(vb,neib.F,neib.S)==2);
	}
	return (state[tme][va][vb] = (ans ? 1 : 2));
}

void Solution(){
	cin >> n >> m;
	forar(i,m){
		int a,b;
		char c;
		cin >> a >> b >> c;
		b--;a--;
		adjout[a].pb(mp(b,int(c-'a')));
	}
	forar(i,n){
		forar(j,n){
			cout << (getdp(i,j,0) == 1 ? 'A' : 'B');
		}
		cout << endl;
	}
}
