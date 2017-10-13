/*
ID: soroosh4
LANG: C++11
TASK: palsquare
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("palsquare.in","r",stdin),freopen("palsquare.out","w",stdout)
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

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

bool ispal(int n,int b){
	int a = n;
	int t = 0;
	while(n>0){
		t*=b;
		t+=n%b;
		n/=b;
	}
	return (a-t == 0);
}

string pr(int n,int b){
	string s;
	while(n>0){
		s+= n%b+48+(int(n%b+48 > 57) * 7);
		n/=b;
	}
	reverse(s.begin(),s.end());
	return s;
}

void Solution(){
	int b;
	cin >> b;
	fori(i,1,301){
		if(ispal(i*i,b)){
			cout << pr(i,b) << ' ' << pr(i*i,b) << '\n';
		}
	}
}
