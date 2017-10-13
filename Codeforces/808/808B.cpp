//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define frs first
#define scnd second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

void Solution();

int n,k;
double seq[2*100*1000];
double sum,cur;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void Solution(){
	cin >> n >> k;
	forar(i,n){
		cin >> seq[i];
	}
	forar(i,k){
		cur += seq[i];
	}
	sum += cur;
	fori(i,k,n){
		cur = cur - seq[i-k];
		cur = cur + seq[i];
		sum += cur;
	}
	cout.precision(10);
	cout << fixed;
	sum = sum / ((double)(n-k+1));
	cout << sum;
}