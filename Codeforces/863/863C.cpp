//In The Name of Allah
//Thu 30/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ull,ull> pllu;

const ll mod = 1e9+7,M = 1e2+5;

void Solution();

ull k,a,b;
ull first,last;
ull scA,scB;
ull mark[4][4];
ull amat[4][4];
ull bmat[4][4];
pllu sc[100];
ull cnt;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void dfs(ull al,ull bob){
	mark[al][bob] = ++cnt;
	if(al != bob){
		if(((al%3)+1) == bob)
			scB++;
		else
			scA++;
	}
	sc[cnt] = make_pair(scA,scB);
	if(mark[amat[al][bob]][bmat[al][bob]]){
		first = mark[amat[al][bob]][bmat[al][bob]];
		last = cnt;
	}else{
		dfs(amat[al][bob],bmat[al][bob]);
	}
}

void Solution(){
	cin >> k >> a >> b;
	forar(i,3){
		forar(j,3){
			cin >> amat[i+1][j+1];
		}
	}
	forar(i,3){
		forar(j,3){
			cin >> bmat[i+1][j+1];
		}
	}
	dfs(a,b);
	scA = scB = 0;
	if(k <= cnt){
		scA = sc[k].F;
		scB = sc[k].S;
	}else{
		scA += sc[first-1].F;
		scB += sc[first-1].S;
		k -= first-1;
		ull t1 = (sc[last].F - sc[first-1].F);
		t1*=(k / (last - first + 1));
		scA += t1;
		t1 = (sc[last].S - sc[first-1].S);
		t1*=(k / (last - first + 1));
		scB += t1;
		k %= (last-first+1);
		scA += sc[first-1+k].F - sc[first-1].F;
		scB += sc[first-1+k].S - sc[first-1].S;
	}
	cout << scA << " " << scB << endl;
}
