//In The Name of Allah
//Thu 30/9/96
#include <vector>
#include <utility>
#include <string>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

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
/*
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;
*/
void Solution();

long long n,m;
long long dp[500][500];
bool mark[500][500];
long long data[500];

int main()
{
	//Init;
	Solution();
	return 0;
}

ll getdp(int pool,int a){
	if(pool < 0)
		return 0;
	if(pool == 0)
		return 1;
	if(mark[pool][a]){
		return dp[pool][a];
	}
	mark[pool][a] = 1;
	ll res = 0;
	for(int i = 0;pool - data[a]*i >= 0;i++){
		res += getdp(pool-(data[a]*i),a-1);
	}
	dp[pool][a] = res;
	return res;
}

void Solution(){
	cin >> m >> n;
	for(int i =0;i<n;i++){
		cin >> data[i];
	}
	for(int i =0;i<m+1;i++){
		if(i%data[0] == 0){
			dp[i][0] = 1;
		}
		mark[i][0] = 1;
	}
	cout << getdp(m,n-1) << endl;
}
