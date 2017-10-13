//In The Name of Allah
//Sun 9/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 3e5+5;

void Solution();

string s1,s2;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

string findpar(string a){
	if(a.length() % 2 == 1){
		return a;
	}
	string c = findpar(a.substr(0,a.length()/2));
	string d = findpar(a.substr(a.length()/2,a.length()));
	if(c<d)
		return c+d;
	else
		return d+c;
}

void Solution(){
	cin >> s1 >> s2;
	cout << (findpar(s1) == findpar(s2) ? "YES" : "NO") << endl;
}
