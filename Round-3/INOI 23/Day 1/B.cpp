//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
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

const ll delta = 10957;

void SolutionA();
void SolutionB();
void SolutionC();

set<string> sols;
ll ansB;
ll temp,temp2;
int colcnt[8];

int main()
{
	Init;
	//WFile;
	SolutionA();
	//SolutionB();
	//SolutionC();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp==0)
		return 1;
	if(exp == 1)
		return base;
	ll v = ppow(base,exp/2);
	v*=v;
	if(exp%2)
		v*=base;
	return v;
}

void SolutionA(){
	int n = 4;
	forar(mask,ppow(2,n*n)){
		string s;
		// rows
		forar(row,n){
			int t = 0;
			forar(col,n){
				int topro = row*n+col;
				t += ((mask & (1<<topro)) ? 1 : 0);
			}
			s += "0123456789"[t];
		}
		// cols
		forar(col,n){
			int t = 0;
			forar(row,n){
				int topro = row*n+col;
				t += ((mask & (1<<topro)) ? 1 : 0);
			}
			s += "0123456789"[t];
		}
		sols.insert(s);
	}
	
	ll m = sols.size();
	Log(m);
	m *= m;
	m %= delta;
	m *= m;
	m %= delta;
	cout << m << endl;
}

void rec(int i){
	if(i == 7){
		temp++;
		if(temp %(10*1000*1000) == 0){
			temp2++;
		}
		forar(k,7){
			if(colcnt[k] != 3)
				return;
		}
		ansB++;
		ansB%=delta;
		return;
	}
	fori(a,0,7){
		fori(b,a+1,7){
			fori(c,b+1,7){
				colcnt[a]++;
				colcnt[b]++;
				colcnt[c]++;
				if(colcnt[a] <= 3 && colcnt[b] <= 3 && colcnt[c] <= 3){
					rec(i+1);
				}
				colcnt[a]--;
				colcnt[b]--;
				colcnt[c]--;
			}
		}
	}
}

void SolutionB(){
	rec(0);
	cout << ansB << endl;
}

ll decomp[100];
ll seqtem[6];

void rec2(int depth){
	if(depth == 0){
		bool is = false;
		ll tsum = 0;
		fori(i,1,6){
			tsum += seqtem[i];
			if(seqtem[i] >= 2)
				is = true;
		}
		if(is){
			decomp[tsum]++;
		}
		return;
	}
	forar(i,11){
		seqtem[depth] = i;
		rec2(depth-1);
	}
}

void SolutionC(){
	rec2(5);
	ll ans = 0;
	forar(i,100){
		decomp[i] *= decomp[i];
		decomp[i] %= delta;
		ans += decomp[i];
		ans %= delta;
		Log(decomp[i]);
	}
	cout << ans << endl;
}
