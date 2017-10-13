/*
ID: soroosh4
LANG: C++11
TASK: milk3
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("milk3.in","r",stdin),freopen("milk3.out","w",stdout)
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

int a,b,c;
bool mark[21][21][21];
set<int> ans;
vector<int> ansarr;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void dfs(int va,int vb,int vc){
	if(mark[va][vb][vc]) return;
	mark[va][vb][vc] = true;
	if(va == 0){
		ans.insert(vc);
		//cout << va << " " << vb << " " << vc << endl;
	}
	int bca = va,bcb = vb,bcc = vc;
	
	// a to b
	vb += va;
	va = 0;
	if(vb > b){
		va = vb - b;
		vb = b;
	}
	dfs(va,vb,vc);
	va = bca;
	vb = bcb;
	vc = bcc;
	
	// a to c
	vc += va;
	va = 0;
	if(vc > c){
		va = vc - c;
		vc = c;
	}
	dfs(va,vb,vc);
	va = bca;
	vb = bcb;
	vc = bcc;
	
	// b to c
	vc += vb;
	vb = 0;
	if(vc > c){
		vb = vc - c;
		vc = c;
	}
	dfs(va,vb,vc);
	va = bca;
	vb = bcb;
	vc = bcc;
	
	// c to b
	vb += vc;
	vc = 0;
	if(vb > b){
		vc = vb - b;
		vb = b;
	}
	dfs(va,vb,vc);
	va = bca;
	vb = bcb;
	vc = bcc;
	
	// c to a
	va += vc;
	vc = 0;
	if(va > a){
		vc = va - a;
		va = a;
	}
	dfs(va,vb,vc);
	va = bca;
	vb = bcb;
	vc = bcc;
	
	// b to a
	va += vb;
	vb = 0;
	if(va > a){
		vb = va - a;
		va = a;
	}
	dfs(va,vb,vc);
	
}

void Solution(){
	cin >> a >> b >> c;
	dfs(0,0,c);
	for(int k : ans)
		ansarr.pb(k);
	forar(i,ansarr.size()){
		cout << ansarr[i];
		if(i != ansarr.size()-1)
			cout << " ";
	}
	cout << endl;
}
