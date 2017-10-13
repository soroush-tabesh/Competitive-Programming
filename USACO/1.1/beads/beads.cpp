/*
ID: soroosh4
LANG: C++11
TASK: beads
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("beads.in","r",stdin),freopen("beads.out","w",stdout)
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

int n;
bool use[360];
char inp[360];
int m;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> inp[i];
	}
	forar(i,n){
		memset(use,0,sizeof use);
		int k = 0;
		char b = inp[i];
		char f;
		use[i] = true;
		k++;
		if(!use[(i+1)%n]){
			f = inp[(i+1)%n];
			use[(i+1)%n] = true;
			k++;
		}else{
			cout << k << '\n';
			return;
		}
		int j = (i-1+n)%n;
		while(!use[j] &&( inp[j] == b || b == 'w' || inp[j] == 'w')){
			use[j]=true;
			k++;
			if(b=='w')
				b = inp[j];
			j = (j-1+n)%n;
		}
		j = (i+2)%n;
		while(!use[j] && (inp[j] == f || f == 'w' || inp[j] == 'w')){
			k++;
			if(f=='w')
				f = inp[j];
			use[j]=true;
			j++;
			j%=n;
		}
		m = max(m,k);
	}
	cout << m << '\n';
}
