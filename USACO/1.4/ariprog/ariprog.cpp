/*
ID: soroosh4
LANG: C++11
TASK: ariprog
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("ariprog.in","r",stdin),freopen("ariprog.out","w",stdout)
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

//map<int,bool> mark[125001];
set<int> seqset;
vector<int> seq;
vector<pii> ans;
bool isseq[125001];
int n,m;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> m;
	// Gen set
	forar(i,m+1){
		forar(j,m+1){
			seqset.insert(i*i+j*j);
			isseq[i*i+j*j] = true;
		}
	}
	for(int k : seqset){
		seq.pb(k);
	}
	// Let's count
	forar(i,seq.size()){
		fori(j,i+1,seq.size()){
			int k = 2;
			int d = seq[j]-seq[i];
			int last = seq[j];
			while(last + d <= 125000 && isseq[last + d]){
				last += d;
				k++;
			}
			if(k>=n){
				ans.pb({d,seq[i]});
			}
		}
	}
	sort(ans.begin(),ans.end());
	if(ans.size()){
		for(pii x : ans){
			cout << x.S << " " << x.F << endl;
		}
	}else{
		cout << "NONE" << endl;
	}
	
}
