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

const ll delta = 10861;

void Solution();

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

bool isgood(int x){
	string s;
	while(x>0){
		s += "0123456789"[x%10];
		x /= 10;
	}
	// a bbb ccc
	if(s[1] == s[2] && s[2] == s[3] && s[4] == s[5] && s[5] == s[6])
		return true;
	// aaa b ccc
	if(s[0] == s[1] && s[1] == s[2] && s[4] == s[5] && s[5] == s[6])
		return true;
	// aaa bbb c
	if(s[0] == s[1] && s[1] == s[2] && s[3] == s[4] && s[4] == s[5])
		return true;
	// aaa bb cc
	if(s[0] == s[1] && s[1] == s[2] && s[3] == s[4] && s[5] == s[6])
		return true;
	// aa bbb cc
	if(s[0] == s[1] && s[2] == s[3] && s[3] == s[4] && s[5] == s[6])
		return true;
	// aa bb ccc
	if(s[0] == s[1] && s[2] == s[3] && s[4] == s[5] && s[5] == s[6])
		return true;
	// abababa
	if(s[0] == s[2] && s[2] == s[4] && s[4] == s[6] && s[1] == s[3] && s[3] == s[5])
		return true;
	return false;
}

void Solution(){
	int m = 0;
	fori(i,1000*1000,7801389){
		if(isgood(i)){
			m++;
		}
	}
	m = m*m;
	m %= delta;
	cout << m;
}