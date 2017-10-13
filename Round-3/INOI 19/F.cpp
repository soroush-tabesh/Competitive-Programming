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

const ll delta = 10337;

void Solution();

int score[6];
int m;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	ll v = ppow(base,exp/2);
	v *= v;
	if(exp%2==1)
		v *= base;
	return v;
}

void solve(int depth){
	if(depth == 0){
		int sum = 0;
		forar(i,6){
			sum += score[i];
		}
		if(sum == 100){
			set<int> tot;
			forar(i,ppow(2,6)){
				int temp = 0;
				forar(w,6){
					if(i & (1<<w)){
						temp += score[w];
					}
				}
				tot.insert(temp);
			}
			m = max(m,int(tot.size()));
		}
	}else{
		fori(i,10,26){
			score[depth-1]=i;
			solve(depth-1);
		}
	}
}

void Solution(){
	solve(6);
	cout << (m*m*m)%delta << endl;
}