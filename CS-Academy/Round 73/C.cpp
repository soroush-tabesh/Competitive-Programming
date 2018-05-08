//In The Name of Allah
//Wed 23/12/96
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

int n;
int para[M],parb[M];
vector<int> cha[M],chb[M];

int main()
{
	Init;
	int t;
	cin >> t;
	while(t--)
		Solution();
	return 0;
}

bool isom(int va,int vb){
	if(cha[va].size() != chb[vb].size())
		return false;
	if(cha[va].size() == 0){
		return true;
	}else if(cha[va].size() == 1){
		return isom(cha[va][0],chb[vb][0]);
	}else{
		return (isom(cha[va][0],chb[vb][0]) && isom(cha[va][1],chb[vb][1])) || (isom(cha[va][0],chb[vb][1]) && isom(cha[va][1],chb[vb][0]));
	}
}

inline void Solution(){
	cin >> n;
	forar(i,n+1){
		cha[i].clear();
		chb[i].clear();
	}
	fori(i,1,n+1){
		cin >> para[i];
		cha[para[i]].pb(i);
	}
	fori(i,1,n+1){
		cin >> parb[i];
		chb[parb[i]].pb(i);
	}
	cout << int(isom(cha[0][0],chb[0][0])) << endl;
}
