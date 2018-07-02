//In The Name of Allah
//Tue 10/4/97
#pragma GCC optimize "-Ofast"
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
#define fori(i,a,b) for(int i = a; i < b;++i)
#define forar(i,n) fori(i,0,n)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LSB(x) (x&(-x))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e6+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

struct fenwick
{
	int* fen = NULL;
	int n = 0;
	void init(int _n){
		n = _n;
		if(fen != NULL)
			delete[] fen;
		fen = (int*)calloc(n,sizeof(int));
	}
	void add(int x,int pos){
		assert(pos>0);
		for(;pos < n;pos+=LSB(pos)) fen[pos] += x;
	}

	int get(int pos){
		int res = 0;
		for(;pos > 0;pos-=LSB(pos))res+=fen[pos];
		return res;
	}
} fen;

int n,m;
int* perm,*pat,*lps,*seq,*asoc;

inline void Solution(){
	cin >> n >> m;
	perm = (int*) calloc(n+10,sizeof(int));
	pat = (int*) calloc(n+10,sizeof(int));
	lps = (int*) calloc(n+10,sizeof(int));
	seq = (int*) calloc(m+10,sizeof(int));
	asoc = (int*) calloc(m+10,sizeof(int));
	forar(i,n){
		int a;
		cin >> a;
		perm[a-1] = i+1;
	}
	forar(i,m){
		cin >> seq[i];
		asoc[i] = seq[i];
	}

	sort(asoc,asoc+m);
	forar(i,m){
		seq[i] = lower_bound(asoc,asoc+m,seq[i])-asoc+1;
	}
	fen.init(n+10);
	forar(i,n){
		pat[i] = fen.get(perm[i]);
		fen.add(1,perm[i]);
	}

	// lps
	fen.init(n+10);
	fori(i,1,n){
		lps[i] = lps[i-1];
		while(lps[i] && pat[lps[i]] != fen.get(perm[i])){
			forar(j,lps[i]-lps[lps[i]-1]){
				fen.add(-1,perm[i-lps[i]+j]);
			}
			lps[i] = lps[lps[i]-1];
		}
		if(pat[lps[i]] == fen.get(perm[i])){
			fen.add(1,perm[i]);
			++lps[i];
		}
	}

	// search
	fen.init(m+10);
	vector<int> ans;
	int pt = 0;
	forar(i,m){
		while(pt && pat[pt] != fen.get(seq[i])){
			forar(j,pt-lps[pt-1]){
				fen.add(-1,seq[i-pt+j]);
			}
			pt = lps[pt-1];
		}
		if(pat[pt] == fen.get(seq[i])){
			fen.add(1,seq[i]);
			++pt;
		}
		if(pt == n){
			forar(j,pt-lps[pt-1]){
				fen.add(-1,seq[i-pt+j]);
			}
			pt = lps[pt-1];
			ans.pb(i-n+2);
		}
	}
	
	cout << ans.size() << endl;
	for(int x : ans){
		cout << x << " ";
	}
}
