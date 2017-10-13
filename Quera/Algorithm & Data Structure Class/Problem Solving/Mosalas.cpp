//In The Name of Allah
//Sat 28/5/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
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

const ll mod = 1e9+7;

void Solution();

int t,n;
int data[100][100];
int sum[100][100];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

int dfs(int i,int j){
	if(sum[i][j] != -1)
		return sum[i][j];
	sum[i][j] = max(dfs(i+1,j),dfs(i+1,j+1))+data[i][j];
	return sum[i][j];
}

void Solution(){
	cin >> t;
	while(t--){
		cin >> n;
		forar(i,n){
			forar(j,i+1){
				sum[i][j] = -1;
				cin >> data[i][j];
			}
		}
		forar(j,n){
			sum[n-1][j] = data[n-1][j];
		}
		cout << dfs(0,0) << endl;
	}
}

