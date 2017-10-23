//In The Name of Allah
//Thu 27/7/96
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

const ll mod = 1e9+7,M = 3e5+5;

void Solution();

int n;
int data[M];
int frsL[M];
bool mark_bendR[M];
bool mark_bendL[M];
bool mark_biofR[M];
bool mark_bendR[M];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

int bendR(){
	
}

int bendL(){
	
}

int biofR(){
	
}

int biofL(){
	
}

int solve(int beg){
	
}

void Solution(){
	cin >> n;
	forar(i,n){
		cin >> data[i];
	}
	int k = 0;
	forar(i,n){
		int x = data[i];
		while(x-- && k < n){
			frsL[k] = i;
			k++;
		}
	}
	cout << solve << endl;
}
