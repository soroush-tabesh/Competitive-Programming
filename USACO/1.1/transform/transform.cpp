/*
ID: soroosh4
LANG: C++11
TASK: transform
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("transform.in","r",stdin),freopen("transform.out","w",stdout)
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

bool a[10][10],b[10][10];
bool t[10][10];
int n;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void cpy(){
	forar(i,n){
		forar(j,n){
			t[i][j] = a[i][j];
		}
	}
}

bool check(){
	forar(i,n){
		forar(j,n){
			if(t[i][j] != b[i][j])
				return false;
		}
	}
	return true;
}

void rot90(){
	forar(i,(n+1)/2){
		fori(j,i,n-i-1){
			swap(t[i][j],t[j][n-i-1]);
			swap(t[i][j],t[n-i-1][n-j-1]);
			swap(t[i][j],t[n-j-1][i]);
		}
	}
}

void flip(){
	forar(i,n){
		forar(j,n/2){
			swap(t[i][j],t[i][n-j-1]);
		}
	}
}

void pr(){
	forar(i,n){
		forar(j,n){
			cout << t[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Solution(){
	cin >> n;
	forar(i,n){
		forar(j,n){
			char c;
			cin >> c;
			if(c == '@'){
				a[i][j] = 1;
			}
		}
	}
	forar(i,n){
		forar(j,n){
			char c;
			cin >> c;
			if(c == '@'){
				b[i][j] = 1;
			}
		}
	}
	int state = 7;
	cpy();
	if(check())
		state = min(6,state);
	rot90();
	if(check())
		state = min(1,state);
	rot90();
	if(check())
		state = min(2,state);
	rot90();
	if(check())
		state = min(3,state);
	
	cpy();
	flip();
	if(check())
		state = min(4,state);
	rot90();
	if(check())
		state = min(5,state);
	rot90();
	if(check())
		state = min(5,state);
	rot90();
	if(check())
		state = min(5,state);
	cout << state << '\n';
}
